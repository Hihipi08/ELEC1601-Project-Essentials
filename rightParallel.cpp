// THIS IS STILL PSEUDOCODE, SORRY
// we can also use this idea for leftParallel

IF left sees wall
AND right sees wall
AND front >= 10 cm
AND left - right > PARALLEL_THRESHOLD:

    rotate clockwise

    WHILE abs(left - right) > PARALLEL_THRESHOLD:
        keep rotating clockwise

    move forward

    // Continue checking parallelism while moving

    WHILE not at corridor centre:
        adjust heading

    // If necessary
    reverse slightly

    STOP