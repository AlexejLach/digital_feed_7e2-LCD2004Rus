//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ***** Print ***** /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
void Print()
{    
  
   if      (err_1_flag == true)
   {
      lcd.setCursor(0, 0);
      lcd.print(" BHИMAHИE:          ");
      lcd.setCursor(0, 1);
      lcd.print("                    ");
      lcd.setCursor(0, 2);
      lcd.print("   УСТАНОВИТЕ УПОРЫ!"); 
      lcd.setCursor(0, 3);
      lcd.print("                    ");
      return;   
   }
   else if (err_2_flag == true)
   {
      lcd.setCursor(0, 0);
      lcd.print(" BHИMAHИE:          ");
      lcd.setCursor(0, 1);     
      lcd.print("                    ");
      lcd.setCursor(0, 2);
      lcd.print("УСТАНОВИТЕ СУППОРТ  ");
      lcd.setCursor(0, 3);
      lcd.print(" В ИСХОДНУЮ ПОЗИЦИЮ!");      
      return;   
   }
   else if (Complete_flag == true)
   {
      lcd.setCursor(0, 0);
      lcd.print("                    ");
      lcd.setCursor(0, 1);     
      lcd.print("OПEPAЦИЯ 3ABEPШEHA! ");
      lcd.setCursor(0, 2);
      lcd.print("                    ");
      lcd.setCursor(0, 3);
      lcd.print("                    ");       
      return;   
   }     
   else if (Ruler_flag == true)
   {

         
     
         lcd.setCursor(0, 0);
         lcd.print("      Линейка       ");
         lcd.setCursor(0, 1);
         if (MX_pos/5%100 <= 0)
         lcd.print("Ocь X: \6    ");
         else 
         lcd.print("Ocь X: \6   -"); 
         snprintf(LCD_Row_7, 7, "%3ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
         lcd.print(LCD_Row_7);
         lcd.print("мм");  
         lcd.setCursor(0, 2);
         if (Size_X_mm%100 <= 0)
         lcd.print("Ocь X: \7    ");
         else 
         lcd.print("Ocь X: \7   -");
         snprintf(LCD_Row_1, 7, "%3ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
         lcd.print(LCD_Row_1);
         lcd.print("мм");         
         lcd.setCursor(0, 3);
         if (Size_Z_mm%100 <= 0)
         lcd.print("Ocь Z:      ");
         else 
         lcd.print("Ocь Z:     -");
         snprintf(LCD_Row_2, 7, "%3ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
         lcd.print(LCD_Row_2); 
         lcd.print("мм"); 
     }
      
//================================    РЕЗЬБА   ===========================================================================================================================================

   if (Mode == Mode_Thread)
   { 
    if (SelectMenu == 1)
     {
      lcd.setCursor(8, 0);
      lcd.print("\2  Pезьба   ");                                                  
      int lenTP = strlen(Thread_Info[Thread_Step].Thread_Print);
      if( lenTP == 4 )
      {
        lcd.setCursor(8, 1);       
        lcd.print(" Шаг: ");
        snprintf(LCD_Row_2, 5, "%s", Thread_Info[Thread_Step].Thread_Print);
        lcd.print(LCD_Row_2);
        //lcd.print("mm");
      }
      else if(lenTP == 3 )
      {
        lcd.setCursor(8, 1);
        lcd.print(" Шаг: ");      
        snprintf(LCD_Row_2, 7, "%stpi", Thread_Info[Thread_Step].Thread_Print); 
        lcd.print(LCD_Row_2);
      } else {
        lcd.setCursor(8, 1);
        lcd.print(" Шаг: ");        
        snprintf(LCD_Row_2, 7, "%s", Thread_Info[Thread_Step].Thread_Print);  
        lcd.print(LCD_Row_2);
      }
      switch(Sub_Mode_Thread)
      {
        case Sub_Mode_Thread_Int:
             lcd.setCursor(0, 0);
             lcd.print(" Bнyтpе "); 
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_4, 3, "%2d", (Thread_Info[Thread_Step].Pass - Pass_Nr+1 + PASS_FINISH + Pass_Fin) + Thr_Pass_Summ );
             lcd.print(LCD_Row_4);
             break;
        case Sub_Mode_Thread_Man:
             lcd.setCursor(0, 0);
             lcd.print(" Pyчная ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_4, 3, "%2d", (Thread_Info[Thread_Step].Pass + PASS_FINISH + Pass_Fin) + Thr_Pass_Summ );
             lcd.print(LCD_Row_4); 
             break;
        case Sub_Mode_Thread_Ext:
             lcd.setCursor(0, 0);
             lcd.print(" Hapyжн ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_4, 3, "%2d", (Thread_Info[Thread_Step].Pass - Pass_Nr+1 + PASS_FINISH + Pass_Fin) + Thr_Pass_Summ );
             lcd.print(LCD_Row_4);
             break;
             }
             lcd.setCursor(8, 3);
             lcd.print(" Об/мин: "); 
             snprintf(LCD_Row_3, 4, "%3d", Thread_Info[Thread_Step].Limit_Print); 
             lcd.print(LCD_Row_3);
             
               ///////         Линейка     ////////
             
             lcd.setCursor(0, 1);
             if (MX_pos/5%100 <= 0)
             snprintf(LCD_Row_7, 20, "\6 %2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             else 
             snprintf(LCD_Row_7, 20, "\6-%2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             lcd.print(LCD_Row_7);
             lcd.print(" ");

             lcd.setCursor(0, 2);
             if (Size_X_mm%100 <= 0)
             snprintf(LCD_Row_6, 20, "X %2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             else 
             snprintf(LCD_Row_6, 20, "X-%2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             lcd.print(LCD_Row_6);
             lcd.print(" ");
                      
             lcd.setCursor(0, 3);
             if (Size_Z_mm%100 <= 0)
             snprintf(LCD_Row_5, 20, "Z %2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             else 
             snprintf(LCD_Row_5, 20, "Z-%2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             lcd.print(LCD_Row_5);
             lcd.print(" "); 
     } 
     else if (SelectMenu == 2) 
     {
         lcd.setCursor(0, 0);
         lcd.print("                    ");
         lcd.setCursor(0, 1);                            
         lcd.print("Чистовых            "); 
         lcd.setCursor(0, 2); 
         lcd.print("Проходов:   \1 \2   ");
         snprintf(LCD_Row_3, 3, "%2d", PASS_FINISH + Pass_Fin);
         lcd.print(LCD_Row_3);
         lcd.setCursor(0, 3); 
         lcd.print("                    ");          
      }
   }
   
//================================    ПОДАЧА СИНХРОННАЯ   ===========================================================================================================================================
  
   else if (Mode == Mode_Feed)
   {  
    if (SelectMenu == 1)
     {  
      lcd.setCursor(8, 0);
      lcd.print("\2  Синхрон  ");
      lcd.setCursor(8, 1);      
      lcd.print(" Подача:");
      snprintf(LCD_Row_2, 5, "%1d.%02d", Feed_mm/100, Feed_mm%100);
      lcd.print(LCD_Row_2);            
      switch(Sub_Mode_Feed)
      {
        case Sub_Mode_Feed_Int:
             lcd.setCursor(0, 0);      
             lcd.print(" Внутре ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7:");        
             break;
        case Sub_Mode_Feed_Man:             
             lcd.setCursor(0, 0);      
             lcd.print(" Ручной ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7:");
                          
             break;
        case Sub_Mode_Feed_Ext:
             lcd.setCursor(0, 0);      
             lcd.print(" Наружн ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7:");            
             break;
            }
              if ( Ap == 5 ){
             snprintf(LCD_Row_4, 5, "%1d.%02d", Ap/100, Ap%100);
             lcd.print(LCD_Row_4);} 
             else {
             snprintf(LCD_Row_4, 5, " %1d.%01d", Ap/100, Ap%100);
             lcd.print(LCD_Row_4);} 
             
             ///////         Линейка     ////////
             
             lcd.setCursor(0, 1);
             if (MX_pos/5%100 <= 0)
             snprintf(LCD_Row_7, 20, "\6 %2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             else 
             snprintf(LCD_Row_7, 20, "\6-%2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             lcd.print(LCD_Row_7);
             lcd.print(" ");

             lcd.setCursor(0, 2);
             if (Size_X_mm%100 <= 0)
             snprintf(LCD_Row_6, 20, "X %2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             else 
             snprintf(LCD_Row_6, 20, "X-%2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             lcd.print(LCD_Row_6);
             lcd.print(" ");
                      
             lcd.setCursor(0, 3);
             if (Size_Z_mm%100 <= 0)
             snprintf(LCD_Row_5, 20, "Z %2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             else 
             snprintf(LCD_Row_5, 20, "Z-%2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             lcd.print(LCD_Row_5);
             lcd.print(" ");              
     } 
   }
   
//================================    ПОДАЧА АСИНХРОННАЯ    ===========================================================================================================================================

   else if (Mode == Mode_aFeed)
   {   
    if (SelectMenu == 1) 
     {
      lcd.setCursor(8, 0);
      lcd.print("\2  Асинхрон ");
      lcd.setCursor(9, 1);      
      lcd.print("Подача: ");
      snprintf(LCD_Row_1, 4, "%3d", aFeed_mm);
      lcd.print(LCD_Row_1);
      //lcd.setCursor(0, 1);
      switch(Sub_Mode_aFeed)
      {
        case Sub_Mode_aFeed_Int:
             lcd.setCursor(0, 0);      
             lcd.print(" Внутре ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7:");             
             break;
        case Sub_Mode_aFeed_Man:
             lcd.setCursor(0, 0);      
             lcd.print(" Ручной ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7:");              
             break;
        case Sub_Mode_aFeed_Ext:
             lcd.setCursor(0, 0);      
             lcd.print(" Наружн ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7:");                
             break;
            } 
              if ( Ap == 5 ){
             snprintf(LCD_Row_4, 5, "%1d.%02d", Ap/100, Ap%100);
             lcd.print(LCD_Row_4);} 
             else {
             snprintf(LCD_Row_4, 5, " %1d.%01d", Ap/100, Ap%100);
             lcd.print(LCD_Row_4);}

               ///////         Линейка     ////////
             
             lcd.setCursor(0, 1);
             if (MX_pos/5%100 <= 0)
             snprintf(LCD_Row_7, 20, "\6 %2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             else 
             snprintf(LCD_Row_7, 20, "\6-%2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             lcd.print(LCD_Row_7);
             lcd.print(" ");

             lcd.setCursor(0, 2);
             if (Size_X_mm%100 <= 0)
             snprintf(LCD_Row_6, 20, "X %2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             else 
             snprintf(LCD_Row_6, 20, "X-%2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             lcd.print(LCD_Row_6);
             lcd.print(" ");
                      
             lcd.setCursor(0, 3);
             if (Size_Z_mm%100 <= 0)
             snprintf(LCD_Row_5, 20, "Z %2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             else 
             snprintf(LCD_Row_5, 20, "Z-%2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             lcd.print(LCD_Row_5);
             lcd.print(" "); 
          
             
    }
        else if (SelectMenu == 2)
                          {
                           lcd.setCursor(0, 0);
                           lcd.print("Текущий  угол:");
                           snprintf(LCD_Row_2, 7, "%3ld.%01ld", Spindle_Angle/1000, Spindle_Angle%1000/100);
                           lcd.print(LCD_Row_2);
                           lcd.print("\5");                           
                           lcd.setCursor(0, 1);
                           lcd.print("Делим круг на:");
                           snprintf(LCD_Row_1, 5,"%3d " , Total_Tooth);
                           lcd.print(LCD_Row_1);
                           lcd.print("\3\4");                           
                           lcd.setCursor(0, 2);
                           lcd.print("Выбор отметки:");
                           snprintf(LCD_Row_3, 5, "%3d ", Current_Tooth);
                           lcd.print(LCD_Row_3);
                           lcd.print("\1\2");
                           lcd.setCursor(0, 3);
                           lcd.print("Угол  сектора:");
                           snprintf(LCD_Row_4, 7, "%3ld.%01ld", Required_Angle/1000, Required_Angle%1000/100);
                           lcd.print(LCD_Row_4);
                           lcd.print("\5");
                          }   
   }
   
//================================    КОНУС ЛЕВЫЙ <    ===========================================================================================================================================

   else if (Mode == Mode_Cone_L)
   {
    if (SelectMenu == 1)
     {
      lcd.setCursor(8, 0);
      snprintf(LCD_Row_1, 8, "<%s ", Cone_Info[Cone_Step].Cone_Print);
      lcd.print(LCD_Row_1);
      lcd.setCursor(13, 0);
      lcd.print(" Kонус ");                                   
      lcd.setCursor(8, 1);      
      lcd.print(" Подача:");
      snprintf(LCD_Row_2, 5, "%1d.%02d", Feed_mm/100, Feed_mm%100);
      lcd.print(LCD_Row_2);
      switch(Sub_Mode_Cone)
      {
        case Sub_Mode_Cone_Int:
             lcd.setCursor(0, 0);      
             lcd.print(" Внутре ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7: ");
             snprintf(LCD_Row_4, 4, "%1d.%01d", Ap/100, Ap%100);
             lcd.print(LCD_Row_4);          
             break;
        case Sub_Mode_Cone_Man:
             lcd.setCursor(0, 0);      
             lcd.print(" Ручной ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7: ");
             snprintf(LCD_Row_4, 4, "%1d.%01d", Ap/100, Ap%100);
             lcd.print(LCD_Row_4);             
             break;
        case Sub_Mode_Cone_Ext:
             lcd.setCursor(0, 0);      
             lcd.print(" Наружн ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7: ");
             snprintf(LCD_Row_4, 4, "%1d.%01d", Ap/100, Ap%100);
             lcd.print(LCD_Row_4);             
             break;
            }
              ///////         Линейка     ////////
             
             lcd.setCursor(0, 1);
             if (MX_pos/5%100 <= 0)
             snprintf(LCD_Row_7, 20, "\6 %2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             else 
             snprintf(LCD_Row_7, 20, "\6-%2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             lcd.print(LCD_Row_7);
             lcd.print(" ");

             lcd.setCursor(0, 2);
             if (Size_X_mm%100 <= 0)
             snprintf(LCD_Row_6, 20, "X %2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             else 
             snprintf(LCD_Row_6, 20, "X-%2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             lcd.print(LCD_Row_6);
             lcd.print(" ");
                      
             lcd.setCursor(0, 3);
             if (Size_Z_mm%100 <= 0)
             snprintf(LCD_Row_5, 20, "Z %2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             else 
             snprintf(LCD_Row_5, 20, "Z-%2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             lcd.print(LCD_Row_5);
             lcd.print(" "); 
     }
     else if (SelectMenu == 2)
     {
      lcd.setCursor(0, 0);
      lcd.print("Конус <");
      snprintf(LCD_Row_1, 5, "%s", Cone_Info[Cone_Step].Cone_Print);
      lcd.print(LCD_Row_1);
      lcd.setCursor(11, 0);
      lcd.print("    \1 \2  ");
      lcd.setCursor(0, 1);
      lcd.print("                    ");
      lcd.setCursor(0, 2);
      lcd.print("                    ");
      lcd.setCursor(0, 3);
      lcd.print("                    ");
     } 
   }
   
//================================    КОНУС ПРАВЫЙ >   ===========================================================================================================================================

   else if (Mode == Mode_Cone_R)
   {
    if (SelectMenu == 1)
     {
      lcd.setCursor(8, 0);
      snprintf(LCD_Row_1, 8, ">%s ", Cone_Info[Cone_Step].Cone_Print);
      lcd.print(LCD_Row_1);
      lcd.setCursor(13, 0);
      lcd.print(" Kонус ");                                   
      lcd.setCursor(8, 1);      
      lcd.print(" Подача:");
      snprintf(LCD_Row_2, 5, "%1d.%02d", Feed_mm/100, Feed_mm%100);
      lcd.print(LCD_Row_2);
      switch(Sub_Mode_Cone)
      {
        case Sub_Mode_Cone_Int:
             lcd.setCursor(0, 0);      
             lcd.print(" Внутре ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7: ");
             snprintf(LCD_Row_4, 4, "%1d.%01d", Ap/100, Ap%100);
             lcd.print(LCD_Row_4);         
             break;
        case Sub_Mode_Cone_Man:
             lcd.setCursor(0, 0);      
             lcd.print(" Ручной ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7: ");
             snprintf(LCD_Row_4, 4, "%1d.%01d", Ap/100, Ap%100);
             lcd.print(LCD_Row_4);             
             break;
        case Sub_Mode_Cone_Ext:
             lcd.setCursor(0, 0);      
             lcd.print(" Наружн ");
             lcd.setCursor(8, 2);
             lcd.print(" Циклов:  ");
             snprintf(LCD_Row_3, 3, "%2d", Pass_Total-Pass_Nr+1);
             lcd.print(LCD_Row_3);
             lcd.setCursor(8, 3); 
             lcd.print(" Съём \7: ");
             snprintf(LCD_Row_4, 4, "%1d.%01d", Ap/100, Ap%100);
             lcd.print(LCD_Row_4);            
             break;
            } 
            ///////         Линейка     ////////
             
             lcd.setCursor(0, 1);
             if (MX_pos/5%100 <= 0)
             snprintf(LCD_Row_7, 20, "\6 %2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             else 
             snprintf(LCD_Row_7, 20, "\6-%2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             lcd.print(LCD_Row_7);
             lcd.print(" ");

             lcd.setCursor(0, 2);
             if (Size_X_mm%100 <= 0)
             snprintf(LCD_Row_6, 20, "X %2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             else 
             snprintf(LCD_Row_6, 20, "X-%2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             lcd.print(LCD_Row_6);
             lcd.print(" ");
                      
             lcd.setCursor(0, 3);
             if (Size_Z_mm%100 <= 0)
             snprintf(LCD_Row_5, 20, "Z %2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             else 
             snprintf(LCD_Row_5, 20, "Z-%2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             lcd.print(LCD_Row_5);
             lcd.print(" "); 
     }
     else if (SelectMenu == 2)
     {
      lcd.setCursor(0, 0);
      lcd.print("Kонус >");
      snprintf(LCD_Row_1, 5, "%s", Cone_Info[Cone_Step].Cone_Print);
      lcd.print(LCD_Row_1);
      lcd.setCursor(11, 0);
      lcd.print("    \1 \2  ");
      lcd.setCursor(0, 1);
      lcd.print("                    ");
      lcd.setCursor(0, 2);
      lcd.print("                    ");
      lcd.setCursor(0, 3);
      lcd.print("                    ");
     }  
   }
   
//================================    РЕЖИМ ШАРА (Шароточка)   ===========================================================================================================================================

   else if (Mode == Mode_Sphere)
   { 
         
     if (SelectMenu == 1 && Sub_Mode_Sphere != Sub_Mode_Sphere_Int)
      {  
         lcd.setCursor(0, 0);
         lcd.print("ШAP \6");
         snprintf(LCD_Row_1, 5, "%2ld.%01ld", Sph_R_mm * 2 / 100, Sph_R_mm * 2 / 10 %10);
         lcd.print(LCD_Row_1);
         lcd.print("мм");
         lcd.setCursor(0, 1);
         lcd.setCursor(8, 1);      
         lcd.print(" Подача:");
         snprintf(LCD_Row_2, 5, "%1d.%02d", Feed_mm/100, Feed_mm%100);
         lcd.print(LCD_Row_2);
          if (Sub_Mode_Sphere == Sub_Mode_Sphere_Man)
          {  
             lcd.setCursor(11, 0);
             lcd.print(" Oтключен");
          }
          else if (Sub_Mode_Sphere == Sub_Mode_Sphere_Ext)
          {  
             lcd.setCursor(11, 0);
             lcd.print("  Включен");
          }
          lcd.setCursor(8, 2);
          lcd.print(" Ножка:\6"); 
          snprintf(LCD_Row_3, 5, "%ld.%02ld", Bar_R_mm*2/100, Bar_R_mm*2%100);
          lcd.print(LCD_Row_3);
          lcd.setCursor(8, 3);
          lcd.print(" Заходов:");
          snprintf(LCD_Row_4, 4, "%3ld", Pass_Total_Sphr+2-Pass_Nr); 
          lcd.print(LCD_Row_4); 
          
              ///////         Линейка     ////////
              
             lcd.setCursor(0, 1);
             if (MX_pos/5%100 <= 0)
             snprintf(LCD_Row_7, 20, "\6 %2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             else 
             snprintf(LCD_Row_7, 20, "\6-%2ld.%02d", abs(MX_pos/5/100), abs(MX_pos/5%100));
             lcd.print(LCD_Row_7);
             lcd.print(" ");

             lcd.setCursor(0, 2);
             if (Size_X_mm%100 <= 0)
             snprintf(LCD_Row_6, 20, "X %2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             else 
             snprintf(LCD_Row_6, 20, "X-%2ld.%02d", abs(Size_X_mm/100), abs(Size_X_mm%100));
             lcd.print(LCD_Row_6);
             lcd.print(" ");
                      
             lcd.setCursor(0, 3);
             if (Size_Z_mm%100 <= 0)
             snprintf(LCD_Row_5, 20, "Z %2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             else 
             snprintf(LCD_Row_5, 20, "Z-%2ld.%02d", abs(Size_Z_mm/100), abs(Size_Z_mm%100));
             lcd.print(LCD_Row_5);
             lcd.print(" "); 
      }
      else if (SelectMenu == 2)
      {  
         lcd.setCursor(0, 0);
         lcd.print("Шиpина peзцa: ");
         snprintf(LCD_Row_1, 5, "%1d.%02d", Cutter_Width/100, Cutter_Width%100);
         lcd.print(LCD_Row_1);
         lcd.print("мм");
         lcd.setCursor(0, 1);
         lcd.print("Шaг по ocи Z: ");
         snprintf(LCD_Row_2, 5, "%1d.%02d", Cutting_Width/100, Cutting_Width%100);
         lcd.print(LCD_Row_2);
         lcd.print("мм"); 
         lcd.setCursor(0, 2);
         lcd.print("                    ");
         lcd.setCursor(0, 3);
         lcd.print("                    ");
      } 
       if (Sub_Mode_Sphere == Sub_Mode_Sphere_Int)
         {
             lcd.setCursor(0, 0);
             lcd.print("                    ");
             lcd.setCursor(0, 1);     
             lcd.print(" Режим невозможен!  ");
             lcd.setCursor(0, 2);
             lcd.print("                    ");
             lcd.setCursor(0, 3);
             lcd.print("                    "); 
         }            
   }
//================================    Делилка  ===========================================================================================================================================
   else if (Mode == Mode_Divider)
{
                       
                           lcd.setCursor(0, 2);   
                           lcd.print("                    ");                       
                           lcd.setCursor(0, 0);
                           lcd.print("    Текущий угол    ");
                           lcd.setCursor(0, 1);
                           lcd.print("       ");
                           snprintf(LCD_Row_2, 9, "%3ld.%01ld", Spindle_Angle/1000, Spindle_Angle%1000/100);
                           lcd.print(LCD_Row_2);
                           lcd.print("\5       "); 
                           lcd.setCursor(0, 3);
                           lcd.print("Сброс кнопкой Селект");                          
                  
                         
                          } 


//================================    Зарезервированный режим  ===========================================================================================================================================
   
   else if (Mode == Mode_Reserve)  //////////////////////////////////////////////////////////////
   {
    lcd.setCursor(0, 0);
    lcd.print("                    ");
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 2);
    lcd.print("                    ");
    lcd.setCursor(0, 3);
    lcd.print("              PE3EPB");
   }
      
 
}
