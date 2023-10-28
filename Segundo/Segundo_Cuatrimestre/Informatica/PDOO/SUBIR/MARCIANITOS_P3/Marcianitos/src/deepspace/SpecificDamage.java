package deepspace;

import java.util.ArrayList;

/**
 *
 * @author laura
 */
public class SpecificDamage extends Damage{
    private ArrayList<WeaponType> weapons; 
    
    SpecificDamage(ArrayList<WeaponType> wl, int s) {
        super(s);
        this.weapons = wl;
    }
    
    // "constructor de copia"
    @Override
    public SpecificDamage copy() {     // ns si esta bien
        return (new SpecificDamage(this.getWeapons(), this.getNShields()));
    }
    
    @Override
    SpecificDamageToUI getUIversion(){
        return new SpecificDamageToUI(this);
    }
    
    @Override
    public SpecificDamage adjust(ArrayList<Weapon> w, ArrayList<ShieldBooster> s) {
        
        int l_nshields = Math.min(s.size(), this.getNShields());

        ArrayList<WeaponType> result = new ArrayList();
        ArrayList<Weapon> aux = new ArrayList(w);

        for (int i = 0; i<this.getWeapons().size(); i++) {
            WeaponType element = this.getWeapons().get(i);
            int indice = this.arrayContainsType(aux, element);
            if (indice != -1) {
                result.add(element);
                aux.remove(indice);
            }
        }                    

        return new SpecificDamage(result, l_nshields);
    }
    
    @Override
    public void discardWeapon(Weapon w) {
        if (getWeapons() != null) 
            getWeapons().remove(w.getType());
    }

    @Override
    public boolean hasNoEffect(){ 
        return (this.getWeapons().isEmpty() && this.getNShields()==0);
    }
    
    public ArrayList<WeaponType> getWeapons(){
        return this.weapons;
    }
    
    @Override
    public String toString() {
        
        String out = super.toString();
        
        if (getWeapons() != null) 
            out += getWeapons().toString();
        
        return out;
    }
}