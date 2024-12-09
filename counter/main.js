const counter = document.getElementById("count");
const inc = document.getElementById("inc");
const reset = document.getElementById("reset");
const dec = document.getElementById("dec");

var count = 0;

inc.onclick = () => {
  count++;
  counter.innerHTML = count;
};
dec.onclick = () => {
  count--;
  counter.innerHTML = count;
};
reset.onclick = () => {
  count = 0;
  counter.innerHTML = count;
};
document.getElementById("gen").onclick = () => {
  var number = Math.trunc(Math.random() * 100);
  document.getElementById("num").innerHTML = number;
};
