// let a = [1,4,3,2,2,4,'s','h','r','a','d','d','h','a'];
// let a = [100,400,300,200,200,400];
// for(let i = 0; i < a.length; i++){
//     a[i] -= a[i] * 0.2;
//     document.writeln(a[i]);
//     // console.log(a[i]);
// }
// // document.writeln(a);
// for(y of a) {
//     document.writeln(y);
// }

// for(y in a) {
//     document.writeln(y);
// }

// let b = [1,2,3,4,5];
// b.pop();
// document.writeln(b);
// b.push(5);
// document.writeln(b);
// b.shift();
// document.writeln(b);
// b.unshift(1);
// document.writeln(b);

// let a = ["Shivendra Srivastava"];
// let b = ["Shraddha Keshari"];
// let c = a.concat(b);
// document.writeln(c);
// document.writeln("<br>");
// c.reverse();
// document.writeln(c);
// document.writeln("<br>");
// c = [5,4,3,2,1];
// c.sort();
// document.writeln(c);
// document.writeln("<br>");
// let x = c.slice(1,4);
// document.writeln(x);
// document.writeln("<br>");
// c.splice(1,2);
// document.writeln(c);
// docment.writeln("<br>");

//create an array to store subujects
// 1. remove first subject
// 2. remove a subject and update the array
// 3. add a subject at the end
let sub = ["Automata", "Data Structures", "Operating Systems", "Digital Electronics"];
document.writeln(sub);
document.writeln("<br>");
document.writeln("<br>");

//1.remove first subject
sub.shift();
document.writeln(sub);
document.writeln("<br>");
document.writeln("<br>");

// let subslice = sub.slice(1,3);
// document.writeln(subslice);

//2. remove a subject and update the array
sub.splice(1,1);
document.writeln(sub);
document.writeln("<br>");
document.writeln("<br>");

// 3. add a subject at the end
sub.push("Computer Networks");
document.writeln(sub);