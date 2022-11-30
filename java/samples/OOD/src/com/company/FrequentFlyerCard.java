package com.company;

import java.time.LocalDate;

public abstract class FrequentFlyerCard implements Discount, StringForFile, Cloneable, Comparable<FrequentFlyerCard> {

    String id;
    String name;
    Address address;
    int frequentFlyerPoints;

    LocalDate dateOfActivation;
    Coupon coupon;

    public FrequentFlyerCard(String id, String name, Address address, int frequentFlyerPoints, LocalDate dateOfActivation) {
        this.id = id;
        this.name = name;
        this.address = address;
        this.frequentFlyerPoints = frequentFlyerPoints;
        this.dateOfActivation = dateOfActivation;
    }

    public void setFrequentFlyerPoints(int frequentFlyerPoints) {
        this.frequentFlyerPoints = frequentFlyerPoints;
    }

    @Override
    public String toString() {
        return "FrequentFlyerCard: " + "id, " + id + ", name, '" + name + '\'' + ", address, " + address + ", frequentFlyerPoints, " + frequentFlyerPoints + ", dateOfActivation, " + dateOfActivation;
    }

    public LocalDate getDate() {
        return dateOfActivation;
    }

    public String getName() {
        return name;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public Address getAddress() {
        return address;
    }

    public Coupon getCoupon() {
        return coupon;
    }


    @Override
    public int compareTo(FrequentFlyerCard o) {
        return Integer.compare(Integer.parseInt(this.id), Integer.parseInt(o.id));
    }

    @Override
    protected FrequentFlyerCard clone() throws CloneNotSupportedException {
        FrequentFlyerCard a = (FrequentFlyerCard) super.clone();
        a.address=(Address) this.address.clone();
        return a;
    }

    public String getDataToSaveToTextFile () {

        return "FrequentFlyerCard: " + "id, " + id + ", name, '" + name + '\'' + ", address, " + address + ", frequentFlyerPoints, " + frequentFlyerPoints + ", dateOfActivation, " + dateOfActivation;

    }

}

