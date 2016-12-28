stringsim <- function(a, b, match_value = 3, mismatch_value = -2, space_value = -5, part_value = -4) {
  .Call("stringsim", utf8ToInt(a), utf8ToInt(b),
        as.integer(c(match_value, mismatch_value, space_value, part_value)))
}
