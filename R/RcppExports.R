# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

getDownAndOutCallPrice <- function(nInt = 0L, Strike = 100, Spot = 95, Vol = 0.2, Rfr = 0.06, Expiry = 0.5, Barrier = 90, nReps = 1000L) {
    .Call(`_optionPriceR_getDownAndOutCallPrice`, nInt, Strike, Spot, Vol, Rfr, Expiry, Barrier, nReps)
}

