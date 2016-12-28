stringsim <- function(a, b) {
  .Call("stringsim", utf8ToInt(a), utf8ToInt(b))
}
