public class Salad extends DietFood implements HealthyFood {

        public String saladName;
        public double saladCalorie;
        public double saladFat;
        public String saladNutritionValue;

        public Salad(String saladName ,double saladCalorie , double saladFat){
           
            super(saladName,saladCalorie,saladFat);
        }

        public Salad(){
            super();
        }

    public void cholesterol (){
        System.out.println("Salads Have 0% Cholesterol ");
    }


        
    
        public calcium (){
            System.out.println("Calcium content is 12%");
        }

    
       
    
        public Salad (String saladNutritionValue){
            this.saladNutritionValue = saladNutritionValue;
        }
    
        @Override
         public String getName()
         {
             return saladName;
         }
         @Override
         public void setName(String saladName){
              this.saladName =  saladName;
         }
    
         @Override
         public String getCalories(){
             return saladCalorie;
         }
    
         @Override
         public String setCalories(double saladCalorie){
             this.saladCalorie = saladCalorie;
         }
    
         @Override
         public double getFat(){
             return saladFat;
         }
    
         @Override
        public void setFat(double saladFat){
            this.saladFat = saladFat;
        }
        @Override
        String getNutritionValue(){
            return saladHealthIssue;
        }
    
    
        @Override
        void setNutritionValue(String saladNutritionValue){
            this.saladNutritionValue = saladNutritionValue;
        }
        
    
    
    
}