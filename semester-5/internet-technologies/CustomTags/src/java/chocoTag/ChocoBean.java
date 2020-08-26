/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chocoTag;

/**
 *
 * @author c3
 */
public class ChocoBean implements java.io.Serializable {
    private String texture;

    public String getTexture() {
        return texture;
    }

    public void setTexture(String texture) {
        this.texture = texture;
    }
    public String[] getValues(){
        if(texture.equals("Chewy"))
            return new String[]{"FiveStar", "BarOne"};
        else if(texture.equals("Crunchy"))
            return new String[]{"Munch", "Kitkat"};
        else
            return new String[]{};
    }
    public ChocoBean() {
    }
    
}
