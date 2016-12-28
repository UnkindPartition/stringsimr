#include <vector>
#include "stringsim/stringsim.h"
#include <R.h>
#include <Rinternals.h>

using namespace std;

static vector<int> sexp2vec(SEXP sexp) {
  size_t len = LENGTH(sexp);
  int *start = INTEGER(sexp);
  return vector<int>(start, start+len);
}

extern "C" {
  SEXP stringsim(SEXP a, SEXP b, SEXP scoring_vec) {
    const int *sv = INTEGER(scoring_vec);
    const Scoring scoring = { sv[0], sv[1], sv[2], sv[3] };
    SEXP result = allocVector(INTSXP, 1);
    INTEGER(result)[0] = similarity(scoring, sexp2vec(a), sexp2vec(b));
    return result;
  }
}
