def simple_interest(principal, rate, time):
    return (principal * rate * time) / 100

def after_interest(principal, rate, time):
    principal += simple_interest(principal, rate, time) 
    return principal

def get_years(principal, rate, interest):
    return (1/(rate/100)) * (((principal + interest)/principal) - 1)

def get_rate(principal, time, interest):
    return ((1/time) * (((principal + interest)/principal) - 1)) * 100

def compound_interest(principle, rate, time, compounded): 
    Amount = principle * (1+((rate/100)/compounded))**(compounded*time)
    return Amount





