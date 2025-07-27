function delay(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

function createBoxes(panel, arr) {
  panel.innerHTML = "";
  arr.forEach(val => {
    const box = document.createElement("div");
    box.className = "box";
    box.textContent = val;
    panel.appendChild(box);
  });
}

function clearHighlight(panel) {
  Array.from(panel.children).forEach(box => {
    box.classList.remove("highlight", "found", "skipped");
  });
}

async function linearSearch(arr, target, panel) {
  const boxes = panel.children;
  let steps = 0;
  for (let i = 0; i < arr.length; i++) {
    clearHighlight(panel);
    boxes[i].classList.add("highlight");
    await delay(400);
    steps++;
    if (arr[i] === target) {
      boxes[i].classList.remove("highlight");
      boxes[i].classList.add("found");
      return { index: i, steps };
    } else {
      boxes[i].classList.remove("highlight");
      boxes[i].classList.add("skipped");
    }
  }
  return { index: -1, steps };
}

async function binarySearch(arr, target, panel) {
  const boxes = panel.children;
  let left = 0, right = arr.length - 1;
  let steps = 0;
  while (left <= right) {
    let mid = Math.floor((left + right) / 2);
    clearHighlight(panel);
    boxes[mid].classList.add("highlight");
    await delay(400);
    steps++;
    if (arr[mid] === target) {
      boxes[mid].classList.remove("highlight");
      boxes[mid].classList.add("found");
      return { index: mid, steps };
    } else {
      boxes[mid].classList.remove("highlight");
      boxes[mid].classList.add("skipped");
      if (target < arr[mid]) right = mid - 1;
      else left = mid + 1;
    }
  }
  return { index: -1, steps };
}

async function runSearch() {
  const input = document.getElementById("arrayInput").value;
  const target = parseInt(document.getElementById("targetInput").value);
  const type = document.getElementById("arrayType").value;
  const resultsBox = document.getElementById("resultsBox");
  const binaryPanel = document.getElementById("binaryPanel");

  let arr = input.split(',').map(x => parseInt(x.trim())).filter(x => !isNaN(x));
  if (arr.length === 0 || isNaN(target)) {
    resultsBox.innerHTML = `<span class="text-danger">❌ Please enter a valid array and target value.</span>`;
    return;
  }

  // ✅ Sort once for both searches if needed
  if (type === "sorted") {
    arr.sort((a, b) => a - b);
  }

  const linearPanel = document.getElementById("linearPanel");
  createBoxes(linearPanel, arr);
  createBoxes(binaryPanel, arr); // Still needed to clear old boxes

  resultsBox.innerHTML = "⏳ Running searches...";

  // ✅ Run linear search with the same array (sorted or not)
  const linear = await linearSearch([...arr], target, linearPanel);

  // ✅ Binary Search runs only if data is sorted
  let binaryResultText = '';
  if (type === "sorted") {
    const binary = await binarySearch([...arr], target, binaryPanel);
    binaryResultText = `
      <strong>⚡ Binary Search</strong><br>
      Index: ${binary.index} <br>
      Steps: ${binary.steps} <br>
      Time Complexity: O(log n)
    `;
  } else {
    binaryPanel.innerHTML = `<div class="text-muted">🔒 Binary Search needs a sorted array.<br>It won't run on random data!</div>`;
    binaryResultText = `
      <strong>⚡ Binary Search</strong><br>
      ❌ Not applicable on unsorted data.<br>
      Please choose "Sorted" to enable it.
    `;
  }

  // Display Results
  resultsBox.innerHTML = `
    <strong>🔍 Linear Search</strong><br>
    Index: ${linear.index} <br>
    Steps: ${linear.steps} <br>
    Time Complexity: O(n) <br><br>
    ${binaryResultText}
  `;
}

const quizData = [
  {
    question: "Which algorithm works on unsorted data?",
    options: ["Binary Search", "Linear Search", "Both", "None"],
    answer: "Linear Search"
  },
  {
    question: "What is the time complexity of Binary Search in the worst case?",
    options: ["O(n)", "O(log n)", "O(1)", "O(n log n)"],
    answer: "O(log n)"
  },
  {
    question: "Why can't Binary Search work on unsorted data?",
    options: [
      "It gets confused easily 😵‍💫",
      "It relies on jumping to the middle, which only works if data is sorted",
      "It searches from the end",
      "It doesn't search at all"
    ],
    answer: "It relies on jumping to the middle, which only works if data is sorted"
  }
];

let currentQ = 0;
let score = 0;

function startQuiz() {
  currentQ = 0;
  score = 0;
  document.getElementById("quizBox").style.display = "block";
  showQuestion();
}

function showQuestion() {
  const q = quizData[currentQ];
  const quizBox = document.getElementById("quizBox");
  quizBox.innerHTML = `
    <h5>Question ${currentQ + 1} of ${quizData.length}</h5>
    <p><strong>${q.question}</strong></p>
    ${q.options.map(opt => `
      <button class="btn btn-outline-dark m-1" onclick="checkAnswer('${opt}')">${opt}</button>
    `).join("")}
  `;
}

function checkAnswer(selected) {
  const correct = quizData[currentQ].answer;
  const quizBox = document.getElementById("quizBox");

  if (selected === correct) {
    score++;
    quizBox.innerHTML += `<p class="text-success mt-2">✅ Correct!</p>`;
  } else {
    quizBox.innerHTML += `<p class="text-danger mt-2">❌ Incorrect! Correct answer: <strong>${correct}</strong></p>`;
  }

  // Wait before next question
  setTimeout(() => {
    currentQ++;
    if (currentQ < quizData.length) {
      showQuestion();
    } else {
      showFinalScore();
    }
  }, 1500);
}

function showFinalScore() {
  const quizBox = document.getElementById("quizBox");
  quizBox.innerHTML = `
    <h4>🎉 Quiz Complete!</h4>
    <p>Your Score: <strong>${score} / ${quizData.length}</strong></p>
    <button class="btn btn-primary" onclick="startQuiz()">🔁 Play Again</button>
  `;
}

function showInfo(type) {
  const infoBox = document.getElementById("extraInfoBox");
  if (type === "linear") {
    infoBox.innerHTML = `
      <h5>🔎 Linear Search</h5>
      <p><strong>How it works:</strong> Goes one by one through each element until it finds the target.</p>
      <p><strong>Best Case:</strong> O(1) – target is first element.</p>
      <p><strong>Worst Case:</strong> O(n) – target is last or not found.</p>
      <p><strong>Best For:</strong> Small or unsorted datasets.</p>
      <p><strong>Space Complexity:</strong> O(1)</p>
      <p><strong>Pros:</strong> Simple, no need for sorting, works with any data.</p>
      <p><strong>Cons:</strong> Slow on large data, can't use structure.</p>
    `;
  } else if (type === "binary") {
    infoBox.innerHTML = `
      <h5>⚡ Binary Search</h5>
      <p><strong>How it works:</strong> Divides sorted list into halves and looks at middle each time.</p>
      <p><strong>Best Case:</strong> O(1) – target is at the middle.</p>
      <p><strong>Worst Case:</strong> O(log n) – keeps halving until target found or not.</p>
      <p><strong>Best For:</strong> Large, sorted datasets.</p>
      <p><strong>Space Complexity:</strong> O(1) (iterative), O(log n) (recursive)</p>
      <p><strong>Pros:</strong> Very fast on sorted data, predictable performance.</p>
      <p><strong>Cons:</strong> Only works on sorted arrays, not suitable for linked lists.</p>
    `;
  } else if (type === "compare") {
    infoBox.innerHTML = `
      <h5>🆚 Linear vs Binary Search</h5>
      <table class="table table-bordered">
        <thead class="table-light"><tr><th>Criteria</th><th>Linear Search</th><th>Binary Search</th></tr></thead>
        <tbody>
          <tr><td>Time Complexity (Best)</td><td>O(1)</td><td>O(1)</td></tr>
          <tr><td>Time Complexity (Worst)</td><td>O(n)</td><td>O(log n)</td></tr>
          <tr><td>Space Complexity</td><td>O(1)</td><td>O(1)</td></tr>
          <tr><td>Requires Sorted Data?</td><td>No</td><td>Yes</td></tr>
          <tr><td>Best Use</td><td>Small or unsorted list</td><td>Large, sorted list</td></tr>
        </tbody>
      </table>
    `;
  }
}
