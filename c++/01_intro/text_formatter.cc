

#include <iostream>
#include <string>
#include <sstream> 
#include <typeinfo> 
std::string formatter(size_t, std::string);
int main ()
{
   std::string text ="Il codice ASCII (si pronuncia askii), che sta per American Standard Computer Information Exchange è la tabella più usata universalmente per la codifica dei dati alfanumerici. Proposto dall'ANSI nel 1963 (definitivo nel 1968) è divenuto uno standard ISO 646. Il codice ASCII standard `e codificato su 7 bit, e quindi può rappresentare al massimo 27 = 128 simboli diversi. Esiste una versione del codice ASCII che usa un byte. Tale codice viene detto Codice ASCII esteso e permette la rappresentazione di 28=256 caratteri, (128 di base con le varianti relative alle diverse lingue + i caratteri speciali e grafici). Caratteristica comune ai due codici è la presenza dei primi 31 caratteri, chiamati caratteri di controllo, che producono un'azione e non sono stampabili. Come si potrà notare il set di caratteri a disposizione non e' poi così ampio, infatti, essendo stata concepita in America, la tabella ASCII standard non comprende le lettere accentate (sconosciute all'ortografia inglese). L'alfabeto latino, usato nella scrittura di molte lingue nel mondo, presenta una grande quantità di varianti grafiche: si va dalle semplici vocali accentate (accento grave à, acuto á, circonflesso â, dieresi ä, tilde ã) a lettere modificate (lettere con barrette, cediglie, segni), lettere speciali usate solo in una lingua, segni di punteggiatura particolari (il punto interrogativo ed il punto esclamativo capovolti usati nello spagnolo), simboli di valuta, e così via, del tutto assenti nell'ortografia inglese. Per questo motivo esistono diverse estensioni della tabella ASCII: lo standard ISO 8859 prevede 15 diverse estensioni, comprese quelle per gli alfabeti diversi dal latino, ma esistono anche ulteriori estensioni non riconosciute dall'ISO e create per esempio dalla Microsoft per i sistemi Windows o dalla Apple per i Macintosh. La tabella ASCII estesa tipicamente utilizzata in Italia è quella dell'Europa occidentale, creata per le lingue germaniche e neolatine (escluso il rumeno). Altre estensioni usate in Europa sono la Centro Europea per i paesi dell'Europa orientale (lingue slave, ungherese, rumeno), la Turca, la Cirillica e la Greca. Di seguito è riortata la tabella ASCII standard (US ASCII ISO 646 International Reference Version).\n";
 



std::string result = formatter(17,text);
std::cout<<"formatted text  :\n "<<result<<std::endl; 


return 0;
}


std::string formatter (size_t max_length,std::string text)
{
 std::ostringstream form; 
 size_t tot_length = text.length(); 
 
 size_t len =tot_length; 
 
 size_t pos= 0;

 
  
 while(len >0  ){ 
     

    for(pos = 0; pos < max_length; pos++) 
    {  
       bool cond = (text[pos] ==10);
       if (cond){ 
                  form<<text.substr(0,pos);  
                  text = text.substr(pos+1);
                  break;
                 }
    }
    
    if(pos == max_length){ 
    pos--;
     
     
     while(text[pos]!= 32 && pos>0){ 
        
        pos--; 
     } 
       if(pos == 0) 
       {
         std::cout<<"Error, the treshold must be less then the length of the longer word in the text"<<std::endl; 
        exit(1);
       }
       form<<text.substr(0,pos)<<std::endl;
       text = text.substr(pos+1);
    } 


    
    len = text.length();
    
   
   
  }

return form.str(); 

} 


    
    
    
        
   
 
