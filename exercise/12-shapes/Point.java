/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package shapespazourekondrej;

/**
 *
 * Bod (Point) potřebujete pro uložení souřadnic středu. Je lepší to ukládat jako objekt než samostatné atributy ve třídě Tvar (Shape) kvůli pozdější rozšiřitelnosti.
 * Bod by v tomto případě dávalo smysl udělat bez setterů a klidně final. Později si ukážeme, že to jde udělat jako record (místo class).
 * 
 * 
 * Jazyková poznámka: Průměr kružnice se anglicky řekne diameter, poloměr radius. Výraz average znamená průměr/průměrný ve statistickém smyslu. 
 * Podle použitých vzorců používáte ten atribut average ve třídě Circle jako poloměr...
    Jinak to řešení vypadá v pořádku.
 * @author ondrejpazourek
 */
public class Point {

	protected double x, y;


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
}
