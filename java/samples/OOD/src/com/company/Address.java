package com.company;

public class Address implements Cloneable, Comparable<Address> {


    int streetNumber;
    String streetName;
    String suburb;
    String city;
    String state;
    int postcode;


    public Address(int streetNumber, String streetName, String suburb, String city, String state, int postcode) {
        this.streetNumber = streetNumber;
        this.streetName = streetName;
        this.suburb = suburb;
        this.city = city;
        this.state = state;
        this.postcode = postcode;
    }

    public String getDataToSaveToTextFile () {

        return streetNumber + "," + streetName + "," + suburb + "," + city + "," + state + "," + postcode;
    }

    public static Address getInstanceFromStringArray(String [] input) {

        return new Address(Integer.parseInt(input[0]), input[1], input[2], input[3], input[4], Integer.parseInt(input[5]));

    }


    @Override
    public String toString() {
        return "Address: " + "streetNumber, " + streetNumber + ", streetName, " + streetName + ", suburb, " + suburb + ", city, " + city + ", state, " + state  + ", postcode, " + postcode ;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return Address.super.clone();
    }

    @Override
    public int compareTo(Address o) {
        return 0;
    }
}
