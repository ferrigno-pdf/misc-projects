def compound_interest(principle, rate, time, compounded): 
    Amount = principle * (1+((rate/100)/compounded))**(compounded*time)
    return Amount





