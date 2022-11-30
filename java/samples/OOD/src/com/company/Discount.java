package com.company;

public interface Discount {

    public double getDiscountAmount(double amount, TicketType type);
    public String getDiscountId();


}
