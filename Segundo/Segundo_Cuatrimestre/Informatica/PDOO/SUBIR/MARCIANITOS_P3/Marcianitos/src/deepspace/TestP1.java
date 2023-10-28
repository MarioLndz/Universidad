/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

import java.util.ArrayList;

/**
 *
 * @author laura
 */
public class TestP1 {
    
    public static void main(String[] args) {												
        // LOOT
        Loot l = new Loot(2,5,1,6,3);
        
        
	// SUPPLIES
        SuppliesPackage sp = new SuppliesPackage(4.5f, 2, 3.1f);
        
	// SHIELD BOOSTER
        ShieldBooster s1 = new ShieldBooster("shield1", 3.4f, 6);
        ShieldBooster s2= new ShieldBooster("shield2", 3.4f, 6);
        ShieldBooster s3 = new ShieldBooster("shield3", 3.4f, 6);
        	
	// WEAPON
        Weapon we1 = new Weapon("weapon", WeaponType.LASER, 4);
        Weapon we2 = new Weapon("weapon", WeaponType.LASER, 4);
        Weapon we3 = new Weapon("weapon", WeaponType.LASER, 4);
        Weapon we4 = new Weapon("weapon", WeaponType.MISSILE, 4);

        WeaponType w1= WeaponType.LASER;
        WeaponType w2= WeaponType.LASER;
        WeaponType w3= WeaponType.LASER;
         WeaponType w4= WeaponType.PLASMA;
        WeaponType w5= WeaponType.PLASMA;
      
        ArrayList<WeaponType> a = new ArrayList<WeaponType> () {{
           // add(w1);
            //add(w2);
            //add(w3);
            //add(w4);
            //add(w5);
        }};
        
        ArrayList<Weapon> a2 = new ArrayList<Weapon> () {{
            add(we1);
            add(we2);
            add(we3);
        }};
        
        ArrayList<ShieldBooster> as = new ArrayList<ShieldBooster> () {{
            add(s1);
            add(s2);
            add(s3);
         }};
        
        Damage d = new Damage(0,0);
        Damage d2 = new Damage(a,0);
        /*
        System.out.println(d2.toString());
        d2.discardWeapon(we4);
        System.out.println(d2.toString());
*/
        System.out.println(d2.hasNoEffect());

    }
}
