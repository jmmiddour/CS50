// Java Script methods that can be helpful here:
// `document.querySelector` to find the specific id to check answer
// `addEventListener` can change the button or text field and display the "Correct" and "Incorrect" messages.

// function insertAfter(refElement, newElement)
// {
//     refElement.parentNode.insertBefore(newElement, refElement.nextSibling);
// }

// document.querySelectorAll.forEach(el => el.addEventListener('click', () => console.log('I was clicked')));

// const buttons = document.querySelectorAll('#q1 button');

// const q1Correct = 'q1d';

// const lastButton = document.querySelector('').append('');

// for (let i = 0; i < buttons.length; i++) {
//     let button = buttons[i];
//     button.addEventListener('click', function onClickHandler() {
//         let color, grade;
//         if (button.id == q1Correct) {
//             color = 'green';
//             grade = 'Correct';
//         } else {
//             color = 'red';
//             grade = 'Wrong';
//         }
    
//         button.style.backgroundColor = color;
//         lastButton.append(grade);
//   });
// }

// for (let i = 0; i < buttons.length; i++) {
//   buttons[i].addEventListener('click', e => {
//     const [color, grade] = e.target.id == q1Correct ? ['green', 'Correct'] : ['red', 'Wrong'];
//     e.target.style.backgroundColor = color;
//     gradeEl.text = grade;
//   });
// }

const buttons = document.querySelectorAll('.q1 button');
const q1Answer = 'q1d';
// const gradeEl = document.createElement('p');
// document.querySelector('#q1').append(gradeEl);

for (let i = 0; i < buttons.length; i++) {
  buttons[i].addEventListener('click', e => {
      console.log('hello')
    const [color, grade] = e.target.id == q1Answer ? ['green', 'Correct'] : ['red', 'Wrong'];
    e.target.style.backgroundColor = color;
    gradeEl.text = grade;
  });
}

// const buttons = document.querySelectorAll('.q1 button');
// const q1Answer = 'q1d';

// for (let i = 0; i < buttons.length; i++) {
//   buttons[i].addEventListener('click', function onClickHandler(e) {
//     for (let i = 0; i < buttons.length; i++) {
//       if (buttons[i] == 
// e.target
// ) {
//         buttons[i].style.backgroundColor =
          
// e.target.id
//  == q1Answer ? 'green' : 'red';
//       } else {
//         buttons[i].style.backgroundColor = '';
//       }
//     }
//   });
// }


// function onClickHandler(e) {
//     e.target.style.backgroundColor = e.target.id == q1Correct ? 'green' : 'red';
//     // removeEventListeners();
// }

// // function removeEventListeners() {
// //     for (let i = 0; i < buttons.length; i++) {
// //         buttons[i].removeEventListener('click', onClickHandler);
// //     }
// // }

// for (let i = 0; i < buttons.length; i++) {
//     buttons[i].addEventListener('click', onClickHandler);
// }




// function handleSubmit() {
    
// }

// function answers()
// {
//     document.querySelector('.q1').valueOf('#right').style.backgroundColor = 'green';
//     let e1 = document.createElement('p').innerHTML = 'Correct';
//     insertAfter(document.getElementById('q1'), e1);

//     let q1w = document.querySelector('.q1').valueOf('.wrong').onclick;
//     q1w.style.backgroundColor = 'red';
//     let e2 = document.createElement('p').innerHTML = 'Incorrect';
//     insertAfter(document.getElementById('q1'), e1);
    
//     let q2 = document.querySelector('#q2').value;
    
//     if (q2.onsubmit === 'lightbulbs')
//     {
//         q2.style.backgroundColor = 'green';
//         insertAfter(document.getElementById('q2'), e1);
//     }
    
//     else
//     {
//         q2.style.backgroundColor = 'red';
//         insertAfter(document.getElementById('q2'), e2);
//     }
    
    
// }

// document.querySelectorAll('form').addEventListener('submit', answers());

// document.querySelector('.q1').valueOf('#right').addEventListener('click', function() {
//     document.querySelector('#right').style.backgroundColor = 'green';
//     let e1 = document.createElement('p').innerHTML = 'Correct';
//     insertAfter(document.getElementById('q1'), e1);
// });

// document.querySelector('.q1').valueOf('.wrong').onclick = function() {
//     document.querySelector('.wrong').style.backgroundColor = 'red';
//     let e1 = document.createElement('p').innerHTML = 'Incorrect';
//     insertAfter(document.getElementById('q1'), e1);
// }

// let q2 = document.querySelector('#q2').value;

// if (q2.onclick === 'lightbulbs')
// {
//     q2.style.backgroundColor = 'green';
//     insertAfter(document.getElementById('q2'), e1);
// }

// else
// {
//     q2.style.backgroundColor = 'red';
//     insertAfter(document.getElementById('q2'), e2);
// }

// document.querySelectorAll('form');

// function correct_btn() {
//     var c = document.getElementById('#right');
//     c.style.backgroundColor = 'green'
//     var e1 = document.createElement('p').innerHTML = "Correct"
//     insertAfter(c, e1)
// }

// function wrong_btn() {
//     var w = document.getElementsByClassName('.wrong');
//     w.style.backgroundColor = 'red'
//     var e2 = document.createElement('p').innerHTML = "Incorrect"
//     insertAfter(w, e2)
// }

// clicked = true;
// $(document).ready(function(){
//     $("button").click(function(){
//         if(clicked){
//             $(this).css('background-color', 'red');
//             clicked = false;
//         } else {
//             $(this).css('background-color', 'green');
//             clicked = true;
//         }
//     });
// });

// $("button").click(function(){
//     var color = clicked ? 'red' : 'green';
//     $(this).css('background-color', color);
//     clicked = !clicked;
// });

// $("button").onclick(function(){
//     $('.correct').css('background-color', 'green');
//     $('form').html(<p>Correct</p>);
// });

// $("button").onclick(function(){
//     $('.wrong').css('background-color', 'red');
//     $('form').html(<p>Incorrect</p>);
// });

// function ansToggle(ans) {
    
//     var a1 = document.getElementsByClassName('q1');
//     var a2 = ans.srcElement.innerHTML();
    
//     if (a1.classList === a2) {
//         a1.classList.toggle('correctAns');
//         var div1 = document.getElementById('q1c');
//         div1.classList.toggle('invisable');
//     }
    
//     else {
//         // var a2 = document.getElementsByClassName('wrong');
//         a1.classList.toggle('wrongAns');
//         var div2 = document.getElementById('q1w');
//         div2.classList.toggle('invisable');
//     }
        
// }
