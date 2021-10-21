function appendGrade(selector) {
    const newEl = document.createElement('p');
    document.querySelector(selector).append(newEl);
    return newEl;
}

const buttons = document.querySelectorAll('#q1 button');
const q1Answer = 'q1d';
const grade1 = appendGrade('#q1');

for (let i = 0; i < buttons.length; i++) {
  buttons[i].addEventListener('click', e => {
    const [color, grade] = e.target.id == q1Answer ? ['green', 'Correct'] : ['red', 'Incorrect'];
    e.target.style.backgroundColor = color;
    grade1.innerHTML = grade;
  });
}

const textBox = document.querySelector('#text-box');
const subBtn = document.querySelector('input[type="submit"]');
const grade2 = appendGrade('#q2');
subBtn.addEventListener('click', onSubmitHandler);

function onSubmitHandler(e) {
    e.preventDefault();
    if (textBox.value.toLowerCase() == 'lightbulbs') {
        textBox.style.backgroundColor = 'green';
        textBox.style.color = 'white';
        grade2.innerHTML = 'Correct';
    } else {
        textBox.style.backgroundColor = 'red';
        textBox.style.color = 'white';
        grade2.innerHTML = 'Incorrect';
    }
}


