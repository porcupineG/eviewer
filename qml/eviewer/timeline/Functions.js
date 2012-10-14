.pragma library

function getBigStepSec(start, stop, width) {
    var minimumStep = 100;
    var maximumSteps = 10;

    var bigStepSec = Math.abs(stop - start);
    var steps = width / minimumStep;

    while (steps > maximumSteps) {

    }


    bigStepSec = 0.001;

    return bigStepSec;
}

function getBigStep(start, stop, width) {
    var bigStep;

    bigStep = width / 8;

    return bigStep;
}

function getSmallStep(start, stop, width) {
    var smallStep;

    smallStep = Math.round(getBigStep(start, stop, width) / 10);

    return smallStep;
}

function getBigRepetitions(start, stop, width) {
    var bigRepetitions;

    bigRepetitions = Math.round(width / getBigStep(start, stop, width));

    return bigRepetitions;
}

function getSmallRepetitions(start, stop, width) {
    var bigRepetitions;

    bigRepetitions = 300

    return bigRepetitions;
}
