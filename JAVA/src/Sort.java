class Page {
  public int key;
  public int value;
  public Page(int key, int value) {
    this.key = key;
    this.value = value;
  }
}

class LRUCache {
  public LRUCache(int capacity) {
    this.capacity = capacity;
  }

  public int get(int key) {
    if (!keyToPage.containsKey(key))
      return -1;

    Page page = keyToPage.get(key);
    cache.remove(page);
    cache.add(page);
    return page.value;
  }

  public void put(int key, int value) {
    if (keyToPage.containsKey(key)) {
      keyToPage.get(key).value = value;
      get(key);
      return;
    }

    if (cache.size() == capacity) {
      Page lastPage = cache.iterator().next();
      cache.remove(lastPage);
      keyToPage.remove(lastPage.key);
    }

    Page page = new Page(key, value);
    cache.add(page);
    keyToPage.put(key, page);
  }

  private int capacity;
  private Set<Page> cache = new LinkedHashSet<>();
  private Map<Integer, Page> keyToPage = new HashMap<>();
}
