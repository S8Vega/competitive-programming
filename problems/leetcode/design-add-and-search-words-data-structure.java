class WordDictionary {

    private Set<String> memory;

    public WordDictionary() {
        this.memory = new HashSet<>();
    }
    
    public void addWord(String word) {
        memory.add(word);
    }
    
    public boolean search(String word) {
        if(memory.contains(word))
            return true;
        if(word.contains("."))  {
            for(String storedWord : memory){
                if(storedWord.length() != word.length())
                    continue;   
                for(int i = 0; i < storedWord.length(); i++){
                    char c1 = storedWord.charAt(i);
                    char c2 = word.charAt(i);
                    if(c2 != '.' && c1 != c2){
                        break;
                    }
                    if(i == storedWord.length() - 1){
                        return true;
                    }
                }
            } 
        }  
        return false;  
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */