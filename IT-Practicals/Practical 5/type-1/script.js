const btnRed = document.querySelector(".el--1");
btnRed.addEventListener("click", function () {
  var textEl = document.querySelector(".paragraph");
  console.log(textEl.textContent);
  if (textEl.classList.contains("green-text")) {
    textEl.classList.remove("green-text");
  }

  if (textEl.classList.contains("blue-text")) {
    textEl.classList.remove("blue-text");
  }

  textEl.classList.add("red-text");
});

const btnGreen = document.querySelector(".el--2");
btnGreen.addEventListener("click", function () {
  var textEl = document.querySelector(".paragraph");
  console.log(textEl.textContent);
  if (textEl.classList.contains("red-text")) {
    textEl.classList.remove("red-text");
  }

  if (textEl.classList.contains("blue-text")) {
    textEl.classList.remove("blue-text");
  }

  textEl.classList.add("green-text");
});

const btnBlue = document.querySelector(".el--3");
btnBlue.addEventListener("click", function () {
  var textEl = document.querySelector(".paragraph");
  console.log(textEl.textContent);
  if (textEl.classList.contains("red-text")) {
    textEl.classList.remove("red-text");
  }

  if (textEl.classList.contains("green-text")) {
    textEl.classList.remove("green-text");
  }

  textEl.classList.add("blue-text");
});

const btn10 = document.querySelector(".el--4");
btn10.addEventListener("click", function () {
  var textEl = document.querySelector(".paragraph");
  console.log(textEl.textContent);
  if (textEl.classList.contains("md-text")) {
    textEl.classList.remove("md-text");
  }

  if (textEl.classList.contains("large-text")) {
    textEl.classList.remove("large-text");
  }

  textEl.classList.add("small-text");
});

const btn20 = document.querySelector(".el--5");
btn20.addEventListener("click", function () {
  var textEl = document.querySelector(".paragraph");
  console.log(textEl.textContent);
  if (textEl.classList.contains("small-text")) {
    textEl.classList.remove("small-text");
  }

  if (textEl.classList.contains("large-text")) {
    textEl.classList.remove("large-text");
  }

  textEl.classList.add("md-text");
});

const btn30 = document.querySelector(".el--6");
btn30.addEventListener("click", function () {
  var textEl = document.querySelector(".paragraph");
  console.log(textEl.textContent);
  if (textEl.classList.contains("small-text")) {
    textEl.classList.remove("small-text");
  }

  if (textEl.classList.contains("md-text")) {
    textEl.classList.remove("md-text");
  }

  textEl.classList.add("large-text");
});

const btnSans = document.querySelector(".el--7");
btnSans.addEventListener("click", function () {
  var textEl = document.querySelector(".paragraph");
  console.log(textEl.textContent);
  if (textEl.classList.contains("cursive-text")) {
    textEl.classList.remove("cursive-text");
  }

  if (textEl.classList.contains("monospace-text")) {
    textEl.classList.remove("monospace-text");
  }

  textEl.classList.add("sans-serif-text");
});

const btnCursive = document.querySelector(".el--8");
btnCursive.addEventListener("click", function () {
  var textEl = document.querySelector(".paragraph");
  console.log(textEl.textContent);
  if (textEl.classList.contains("sans-serif-text")) {
    textEl.classList.remove("snas-serif-text");
  }

  if (textEl.classList.contains("monospace-text")) {
    textEl.classList.remove("monospace-text");
  }

  textEl.classList.add("cursive-text");
});

const btnMonospace = document.querySelector(".el--9");
btnMonospace.addEventListener("click", function () {
  var textEl = document.querySelector(".paragraph");
  console.log(textEl.textContent);
  if (textEl.classList.contains("sans-serif-text")) {
    textEl.classList.remove("sans-serif-text");
  }

  if (textEl.classList.contains("cursive-text")) {
    textEl.classList.remove("cursive-text");
  }

  textEl.classList.add("monospace-text");
});