// This is my first JavaScript code!
console.log('Hello World');
// Variable cannot be a reserved keyword
// Should be meaningful and cannot start with a number
// Cannot contain a space or hyphen
// Are case sensitive
let firstName = 'Joe';
let lastName = 'Zhuang';
console.log(firstName);
// Cannot reassign a constant
const interestRate = 0.3;
console.log(interestRate);
// Primitives / Value Types
// string, number, boolean, undefined, null
let name = 'Mosh'; // String Literal
let age = 30; // Number Literal
let isApproved = false; // Boolean Literal
let undefinedName = undefined;
let selectedColor = null;
// typeof name === 'string'
// typeof age === 'number'
// typeof isApproved === 'boolean'
// typeof undefinedName === 'undefined'
// Reference Types
// object, array, function
// typeof selectedColor === 'object'
let person = {
    name: 'Mosh',
    age: 30
};
// Dot Notation
person.name = 'John';
// Bracket Notation
let selection = 'name';
person[selection] = 'Mary';
console.log(person.name);
// arrays
let selectedColors = ['red', 'blue'];
selectedColors[2] = 1;
console.log(selectedColors[0]);
console.log(selectedColors.length);
// functions
// parameters and arguments
// Performing a task
function greet(name, lastName) {
    console.log('Hello, ' + name + ' ' + lastName);
}
greet('John', 'Smith');
// Calculating a value
function square(number) {
    return number * number;
}
let number = square(2);
console.log(number); //console.log(square(2));