var x = document.querySelector("#btn");
// var z = "light"
// x.addEventListener('click', ()=>{
//     if(z === "light"){
//         document.body.style.backgroundColor = "red";
//         z = "dark";
//         console.log('dark')
//     } else {
//         document.body.style.backgroundColor = "white";
//         z = "light";
//         console.log('light')
//     }
// })
// var y=()=>{
//     console.log('this is new event')
// }
x.addEventListener('click', ()=> {
    alert('Button Clicked')
})
// x.addEventListener('click', ()=> {
//     console.log('CS')
// })
// x.addEventListener('click', ()=> {
//     console.log('957')
// })

// x.removeEventListener('click', ()=> {
//     console.log('Shivendra')
// })

var inputField = document.querySelector("input");
inputField.addEventListener('keyup', ()=> {
    console.log(inputField.value)
})
