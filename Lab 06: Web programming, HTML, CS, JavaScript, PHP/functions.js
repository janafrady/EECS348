/*
Name: Jana Frady
KUID: 3085051
Lab Session: Thursday 4 p.m.
Lab Assignment Number: 06
Program Description: This creates functions for practice2 and practice3.
Collaborators: None
*/

// changes border color, border width, and background color from user-inputted values
function alert_paragraph_color() {    
    var border_R = document.getElementById("border_R").value;
    var border_G = document.getElementById("border_G").value;
    var border_B = document.getElementById("border_B").value;
    var border_width = document.getElementById("border_width").value;
    var backR = document.getElementById("backR").value;
    var backG = document.getElementById("backG").value;
    var backB = document.getElementById("backB").value;

    const element = document.getElementById("demo");
    
    element.style.borderColor = `rgb(${border_R},${border_G},${border_B})`;
    element.style.borderWidth = border_width;
    element.style.backgroundColor = `rgb(${backR},${backG},${backB})`;
}

// checks if both passwords are more than eight characters and the same
function validate(){
    var first = document.getElementById("first").value;
    var second = document.getElementById("second").value;
    if (first.length < 8){
        alert("The first password is less than eight characters.")
    } else if (second.length < 8) {
        alert("The second password is less than eight characters.")
    } else if (first != second){
        alert("The passwords do not match")
    } else{
        alert("Passwords are valid")
    }
}