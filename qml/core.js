.pragma library

var viewWidth = 0;
var viewHeight = 0;

var viewStartSec = 0;
var viewStopSec = 100;
var secPerPixel = 0;

var contentStartSec = 0;
var contentStopSec = 100;

var sourceSize = 4;
var sourceStartNum = 0;

var timelineHeight = 30;
var sourceSpacing = 10;

var maximumBigSteps = 10;
var minimumBigStepPx = 100;

var sideBarWidth = 50

function setWidth(w) { viewWidth = w / 10}
function getWidth() { console.log(viewWidth); return viewWidth; }
function setHeight(h) { viewHeight = h }

