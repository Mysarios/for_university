// First Quest
console.log();
console.log("\x1b[42m" ,"First Quest:");
console.log("\x1b[0m");

function ShowType(variable) {
 console.log("Type = " + typeof variable + ";  Amount = " + variable);
}

let Text = "Hi, my name is Dima";
let Num = 5664;
let Check = true;

ShowType(Text);
ShowType(Num);
ShowType(Check);

// Second Quest
console.log();
console.log("\x1b[42m" ,"Second Quest:");
console.log("\x1b[0m");

const ArrayOfStrings = ["I " , "wonna " , "learn " , "JS!"];

for(let string of ArrayOfStrings){
 console.log(string);
}

// Third Quest
console.log();
console.log("\x1b[42m" , "Third Quest:");
console.log("\x1b[0m");

let Week = {
 FirstDayOfWeek: "Sunday",
 DayOfWeekend: "Monday",

 GetDayOfWeekend: function() {
  console.log("U will relax at: " + this.DayOfWeekend);
 },

 ChangeFirstDayOfWeek: function(Day){
   this.FirstDayOfWeek=Day;
 },

 set property(Day){
   this.DayOfWeekend = Day;
 },

};

Object.defineProperty(Week, "Amount_Of_Days", {
 value: 7,
 writable: false,
 enumerable: false,
 configurable: false
});
Object.defineProperty(Week, "Educational", {
 value:true,
 writable: false,
 enumerable: false,
 configurable: false
});
Object.defineProperty(Week, "FavoriteDay", {
 value:"Wensday!!!,of course!",
 writable: false,
 enumerable: false,
 configurable: false
});

console.log("At this Week we have: " + Week.Amount_Of_Days + " Days!")
console.log("It's Educational week? : " + Week.Educational )
console.log("Which u favorite day? : " + Week.FavoriteDay )

console.log("First Day at week? : " + Week.FirstDayOfWeek )
Week.ChangeFirstDayOfWeek("Monday")
console.log("First Day at week? : " + Week.FirstDayOfWeek )

Week.GetDayOfWeekend();
Week.property = "Friday"
Week.GetDayOfWeekend();