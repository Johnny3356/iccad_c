# --- 目錄設定 ---
SRCDIR   := src
OBJDIR   := obj
BINDIR   := bin

# --- 工具和選項 ---
CXX      := g++
CXXFLAGS := -std=c++17 -O2 -Wall -I$(SRCDIR)

# --- 執行檔名稱 ---
TARGET   := $(BINDIR)/parser

# --- 原始碼與對應物件檔 ---
SRCS     := $(wildcard $(SRCDIR)/*.cpp)
OBJS     := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

.PHONY: all clean

# 預設目標：編譯並連結
all: $(TARGET)

# 確保 obj/ bin/ 存在
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# 連結所有物件檔成最終執行檔
$(TARGET): $(OBJDIR) $(BINDIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# 編譯單一 .cpp 為 .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理中間檔與執行檔
clean:
	rm -rf $(OBJDIR) $(BINDIR)