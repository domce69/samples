package com.company;

public class Coupon implements Discount, StringForFile, Cloneable, Comparable <Coupon> {

    String id;
    double discountValue;

    public Coupon(String id, double discountValue) {
        this.id = id;
        this.discountValue = discountValue;
    }

    public double getValue() {

        return discountValue;
    }

    public static Coupon getInstanceFromStringArray(String [] input) {

        return new Coupon(input[0], Double.parseDouble(input[1]));

    }

    @Override
    public double getDiscountAmount(double amount, TicketType type) {
        return discountValue;
    }

    @Override
    public String getDiscountId() {
        return id;
    }

    public String getDataToSaveToTextFile () {

        return id + "," + discountValue;
    }

    @Override
    public String toString() {
        return "" +
                "id: " + id +
                ", discountValue: " + discountValue;
    }

    @Override
    public int compareTo(Coupon o) {
        return Integer.compare(Integer.parseInt(this.id), Integer.parseInt(o.id));
    }

    @Override
    protected Coupon clone() throws CloneNotSupportedException {
        Coupon a = (Coupon) super.clone();
        return a;
    }
}

