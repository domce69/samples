package com.company;

import java.time.LocalDate;
import java.time.Period;


public class TitaniumFrequentFlyer extends PlatinumFrequentFlyer implements Cloneable{

    double numberOfYears;

    public TitaniumFrequentFlyer(String id, String name, Address address, int frequentFlyerPoints, LocalDate dateOfActivation, double numberOfYears) {
        super(id, name, address, frequentFlyerPoints, dateOfActivation);
        this.numberOfYears = numberOfYears;
    }

    public TitaniumFrequentFlyer getInstanceFromStringArray(String [] input) {

        Address addr = new Address(Integer.valueOf(input[2]), input[3], input[4], input[5], input[6], Integer.parseInt(input[7]));

        return new TitaniumFrequentFlyer(input[0], input[1], addr, Integer.parseInt(input[8]), LocalDate.parse(input[9]), Double.parseDouble(input[10]));

    }

    public double calCoupon() {

        double yearlyCoupon;
        if (numberOfYears > 5 && frequentFlyerPoints >= 100000 && frequentFlyerPoints <= 300000 || frequentFlyerPoints > 300000) {

            yearlyCoupon = frequentFlyerPoints * 0.03;
        }
        else if (frequentFlyerPoints > 100000 && frequentFlyerPoints < 300000){

            yearlyCoupon = frequentFlyerPoints * 0.02;
        }

        else {

            yearlyCoupon = frequentFlyerPoints * 0.015;
        }

        return coupon.discountValue = yearlyCoupon;

    }

    @Override
    public double getDiscountAmount(double amount, TicketType type) {

        double discountAmount = 0;
        if(type == TicketType.economyClass){

            discountAmount += amount * 0.01;

        }

        else {

            discountAmount += amount * 0.10;

        }

        return discountAmount;
    }

    @Override
    public String getDiscountId() {

        return id;
    }

    @Override
    public String toString() {
        return super.toString() + " Number of Years: " + numberOfYears;
    }

    @Override
    protected TitaniumFrequentFlyer clone() throws CloneNotSupportedException {
        TitaniumFrequentFlyer a = (TitaniumFrequentFlyer) super.clone();
        a.address=(Address) this.address.clone();
        return a;
    }
}
