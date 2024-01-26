/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package cary.pazourekondrej;

/**
 *
 * @author ondrejpazourek
 */
public class Point {

	double x, y;


	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}

	// Copy constructer
	public Point(Point b) {
		this(b.x, b.y);
	}

	// Distance between points which are passed through the params
	public double distanceBetweenTwoPoints(Point a, Point b) {
		return Math.sqrt(Math.pow(b.x - a.x, 2) + Math.pow(b.y - a.y, 2)); 
	}
	
	// Distance between the current point and the other one
	public double distanceTo(Point otherPoint) {
        return Math.sqrt(Math.pow(otherPoint.x - this.x, 2) + Math.pow(otherPoint.y - this.y, 2));
    }

	// Getters for x and y
	public double getX() { return x; }
	
	public double getY() { return y; }
	
	// Setter	 methods if needed
	public void setX(double x) {
		this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }
	
	@Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}
