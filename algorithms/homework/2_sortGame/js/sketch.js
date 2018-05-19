/*jshint esversion: 6 */

// Main content
var nElements        = 12;
var elements         = [];
var steps            = [];
var currentStepIndex = 0;
var isDone           = false;

// UI elements
var bars        = [];
var barsText    = [];
var barWidth     = 30;
var barSpace     = 4+barWidth;
var maxBarHeight = 150;
var paddingTop   = 110;
var paddingLeft  = -10;
var duringAnimation = 0;
var highlightIndexes = [];

function setup() {
  frameRate(14);

  // Set font
  textFont("Roboto"); 

  // Create canvas
  createCanvas(470, 400);
  textSize(18);
  noStroke();
  smooth();

  // Generate matrix of elements
  var elementsValues = generateRandomArray(nElements);
  //elementsValues = [91,56,2,33,87]; // Static value for debug
  elementsValues.forEach((value, index) => {
    elements.push([index, value]);
  });
  //debug(elements);

  // Sort
  steps = bubbleSortArray(elements);
  steps.forEach((value, index) => {
    //debug(value);
  });
  
  drawBars();
}

// Main loop
function draw() {
  // Draw bars if has no animation
  //if(duringAnimation==0)
    drawBars();
  
  // Run next step animation
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

    if(duringAnimation) {
      if(highlightIndexes.includes(elements[i-1][0]))
        fill(30,200,200);
      else
        fill(30,100,200);
    }

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
  //resetSteps();
  nextStep();
}

function nextStep() {
  // Start animation to state 1
  if(duringAnimation==0) { // Highlight
    //debug("===================");
    elements.forEach((value, index) => {
      if(steps[currentStepIndex+1][index][1]!=value[1]){
        highlightIndexes.push(value[0]);
        //debug(steps[currentStepIndex+1][index][0]+" | "+value[0]);
      }
    });
    duringAnimation+=1;
    //debug(highlightIndexes);
    return;
  }
  
  // Change animation state from 1 to 2
  if(duringAnimation == 1){
    duringAnimation+=1;
  }

  // Continue if animation is done
  if(duringAnimation == 2){
    duringAnimation = 0;
    highlightIndexes = [];
  }

  // Change current step
  if(currentStepIndex!=steps.length-1) {
    currentStepIndex = currentStepIndex+1;
    if(currentStepIndex==steps.length-1)
      isDone = true;
  }

  // Change array position
  elements = steps[currentStepIndex];
}

function resetSteps() {
  isDone = false;
  currentStepIndex=0;
}
