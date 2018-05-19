/*jshint esversion: 6 */

// Main content
var nElements        = 18;
var elements         = [];
var steps            = [];
var currentStepIndex = 0;
var isDone           = false;

// UI elements
var bars        = [];
var barsText    = [];
var barWidth     = 26;
var barSpace     = 4+barWidth;
var maxBarHeight = 150;
var paddingTop   = 110;
var paddingLeft  = -10;

function setup() {
  frameRate(30);

  // Set font
  textFont("Roboto"); 

  // Create canvas
  createCanvas(470, 400);
  textSize(18);
  noStroke();
  smooth();

  // Generate matrix of elements
  var elementsValues = generateRandomArray(nElements);
  //elementsValues = [54,56,2,33,87,100,52,71]; // Static value for debug
  elementsValues.forEach((value, index) => {
    elements.push([index, value]);
  });
  //debug(elements);

  // Sort
  steps = bubbleSortArray(elements);
  steps.forEach((value, index) => {
    //debug(value);
  });
}

// Main draw
function draw() {  
  drawBars();
  nextStep();
}


// Draw all bars
function drawBars() {
  background(255);

  var i;

  // Draw bars
  bars = [];
  fill(30,100,200);
  for (i = 1; i < nElements+1; i++) {
    const elementSize = 100-elements[i-1][1];
    const barHeight   = maxBarHeight;

    bars.push(quad(
        paddingLeft+i*barSpace,          elementSize+paddingTop,
        paddingLeft+i*barSpace+barWidth, elementSize+paddingTop,
        paddingLeft+i*barSpace+barWidth, barHeight+paddingTop,
        paddingLeft+i*barSpace,          barHeight+paddingTop
      ));
  } 

  // Draw bar number
  fill(255);
  textSize(10);
  textAlign(CENTER);
  for (i = 1; i < nElements+1; i++) {
    barsText.push(
      text("#"+elements[i-1][0]+"\n"+elements[i-1][1], barSpace*i-10+(barWidth/2), maxBarHeight+paddingTop-20)
    );
  }  
}

function mousePressed() {
  nextStep();
}

function nextStep() {
  // Change current step
  if(currentStepIndex!=steps.length-1) {
    currentStepIndex = currentStepIndex+1;
    if(currentStepIndex==steps.length-1)
      isDone = true;
  }

  // Change array position
  elements = steps[currentStepIndex];
}

function swap (x, y) {
  [elements[y], elements[x]] = [elements[x], elements[y]];
}

function debug (debug_content) {
  document.getElementById('debug').innerHTML =
    document.getElementById('debug').innerHTML + '<br>' + JSON.stringify(debug_content);
}