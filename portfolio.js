// Create toggle button
const toggleBtn = document.createElement("button");
toggleBtn.id = "themeToggle";
toggleBtn.innerText = "🌙 Dark Mode";
document.body.appendChild(toggleBtn);

let darkMode = false;

toggleBtn.addEventListener("click", () => {
  darkMode = !darkMode;
  document.body.classList.toggle("dark-mode");

  toggleBtn.innerText = darkMode ? "☀️ Light Mode" : "🌙 Dark Mode";
});
