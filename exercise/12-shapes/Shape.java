/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package shapespazourekondrej;

/**
 *
 * @author ondrejpazourek
 */
public abstract class Shape {
	protected final Point center;
	
	public Shape(Point center) {
        this.center = center;
    }
	
	public abstract double getArea();
	public abstract double getDiameter();
	
}
