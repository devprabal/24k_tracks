const toggleButton = document.getElementById('lightDarkToggleButton');
const bodyElement = document.body;

toggleButton.addEventListener('click', () => {
  bodyElement.classList.toggle('dark-mode');
});
