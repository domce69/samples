package com.company;

public class AirTicket implements Cloneable, Comparable<AirTicket> {

    int ticketId;
    String name;
    String departureCity;
    String destinationCity;
    int flightNumber;
    TicketType ticType;
    double price;
    DiscountType discountType;
    double discountAmount;

    public AirTicket(int ticketId, String name, String departureCity, String destinationCity, int flightNumber, double price, double discountAmount, TicketType ticType, DiscountType discountType) {
        this.ticketId = ticketId;
        this.name = name;
        this.departureCity = departureCity;
        this.destinationCity = destinationCity;
        this.flightNumber = flightNumber;
        this.price = price;
        this.discountAmount = discountAmount;
        this.ticType = ticType;
        this.discountType = discountType;
    }

    public String getDataToSaveToTextFile () {

        return ticketId + "," + name + "," + departureCity + "," + destinationCity + "," + flightNumber + "," + price + "," + discountAmount + "," + TicketType.values().toString() + "," + DiscountType.values().toString();
    }

    public static AirTicket getInstanceFromStringArray(String [] input) {

        TicketType tt;

        if (input[7].trim().equalsIgnoreCase(TicketType.economyClass.name())) {

            tt = TicketType.economyClass;
        }

        else if (input[7].trim().equalsIgnoreCase(TicketType.businessClass.name())) {

            tt = TicketType.businessClass;

        }

        else {
            tt = TicketType.firstClass;
        }

        DiscountType dt;

        if (input[8].trim().equalsIgnoreCase(DiscountType.cardDiscount.name())) {

            dt = DiscountType.cardDiscount;

        }

        else {
            dt = DiscountType.coupon;
        }


        return new AirTicket(Integer.parseInt(input[0]), input[1], input[2], input[3], Integer.parseInt(input[4]), Double.parseDouble(input[5]), Double.parseDouble(input[6]), tt, dt);
    }

    public static String[] convertDataFromFileToStringArray(String input) {

        return input.split(",");

    }

    @Override
    public String toString() {
        return
                ticketId + ", " + name + ", " + departureCity + ",  " + destinationCity  + ", " + flightNumber + ", " + price + ", " + discountAmount + ", " + ticType + ", " + discountType ;
    }

    @Override
    public int compareTo(AirTicket o) {
        return Integer.compare((this.ticketId), (o.ticketId));
    }
}

