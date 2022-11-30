package com.company;

import java.time.LocalDate;

public class PlatinumFrequentFlyer extends FrequentFlyerCard implements Cloneable {

    double yearlyCoupon;
    CardRegisterView crv = new CardRegisterView();

    public PlatinumFrequentFlyer(String id, String name, Address address, int frequentFlyerPoints, LocalDate dateOfActivation) {
        super(id, name, address, frequentFlyerPoints, dateOfActivation);

    }

    public PlatinumFrequentFlyer getInstanceFromStringArray(String [] input) { //Fix

        Address addr = new Address(Integer.valueOf(input[2]), input[3], input[4], input[5], input[6], Integer.parseInt(input[7]));

        return new PlatinumFrequentFlyer(input[0], input[1], addr, Integer.parseInt(input[8]), LocalDate.parse(input[9]));

    }

    public double calCoupon() {

        if (frequentFlyerPoints < 10000) {
            yearlyCoupon = frequentFlyerPoints * 0.005;
        } else {

            yearlyCoupon = frequentFlyerPoints * 0.01;
        }

        return coupon.discountValue = yearlyCoupon;

    }

    @Override
    public double getDiscountAmount(double amount, TicketType type) {

        double discountAmount = 0;
        if (type == TicketType.economyClass) {

            discountAmount = amount * 0.01;

        } else {

            discountAmount = amount * 0.05;
        }

        return discountAmount;
    }

    @Override
    public String getDiscountId() {
        return id;
    }

    @Override
    public String toString() {
        return super.toString();
    }

    @Override
    protected PlatinumFrequentFlyer clone() throws CloneNotSupportedException {
        PlatinumFrequentFlyer a = (PlatinumFrequentFlyer) super.clone();
        a.address=(Address) this.address.clone();
        return a;
    }

}



