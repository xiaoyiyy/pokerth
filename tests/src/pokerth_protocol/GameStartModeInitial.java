
package pokerth_protocol;
//
// This file was generated by the BinaryNotes compiler.
// See http://bnotes.sourceforge.net 
// Any modifications to this file will be lost upon recompilation of the source ASN.1. 
//

import org.bn.*;
import org.bn.annotations.*;
import org.bn.annotations.constraints.*;
import org.bn.coders.*;
import org.bn.types.*;




    @ASN1PreparedElement
    @ASN1Sequence ( name = "GameStartModeInitial", isSet = false )
    public class GameStartModeInitial implements IASN1PreparedElement {
            
@ASN1SequenceOf( name = "playerSeats", isSetOf = false ) 

    @ASN1ValueRangeConstraint ( 
		
		min = 2L, 
		
		max = 10L 
		
	   )
	   
        @ASN1Element ( name = "playerSeats", isOptional =  false , hasTag =  false  , hasDefaultValue =  false  )
    
	private java.util.Collection<NonZeroId>  playerSeats = null;
                
  
        
        public java.util.Collection<NonZeroId>  getPlayerSeats () {
            return this.playerSeats;
        }

        

        public void setPlayerSeats (java.util.Collection<NonZeroId>  value) {
            this.playerSeats = value;
        }
        
  
                    
        
        public void initWithDefaults() {
            
        }

        private static IASN1PreparedElementData preparedData = CoderFactory.getInstance().newPreparedElementData(GameStartModeInitial.class);
        public IASN1PreparedElementData getPreparedData() {
            return preparedData;
        }

            
    }
            