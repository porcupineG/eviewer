var viewStartSec = 0;
var viewStopSec = 100;

var contentStartSec = 0;
var contentStopSec = 100;

var sourceHeight = 30;
var timelineHeight = 30;
var sourceSpacing = 10;

var maximumBigSteps = 10;
var minimumBigStepPx = 100;

var sideBarWidth = 50

function getBigStepSec(width) {

    bigStepSec = 0.001;

    return bigStepSec;
}

function getBigStep(width) {
    var bigStep;

    bigStep = width / 8;

    return bigStep;
}

function getSmallStep(width) {
    var smallStep;

    smallStep = Math.round(getBigStep(width) / 10);

    return smallStep;
}

function getBigRepetitions(width) {
    var bigRepetitions;

    bigRepetitions = Math.round(width / getBigStep(width));

    return bigRepetitions;
}

function getSmallRepetitions(width) {
    var bigRepetitions;

    bigRepetitions = 300

    return bigRepetitions;
}
