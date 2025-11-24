// Select the box and button
const box = document.getElementById("colorBox");
const btn = document.getElementById("colorBtn");

// Random color generator
function getRandomColor() {
    return "#" + Math.floor(Math.random() * 16777215).toString(16);
}

// Change color when button is clicked
btn.addEventListener("click", () => {
    const randomColor = getRandomColor();
    box.style.backgroundColor = randomColor;
    box.textContent = "New Color: " + randomColor;
});