// 简体中文字库：使用 LovyanGFX 自带的 efont CN（BSD 授权，含 Unicode 映射表）
// 16px 对应原 FONT_SMALL，24px 对应原 FONT_LARGE
#pragma once

#include <LovyanGFX.hpp>

extern "C"
{
  extern const uint8_t lgfx_efont_cn_16[];
  extern const uint8_t lgfx_efont_cn_24[];
}

static const lgfx::U8g2font FONT_CN_16(lgfx_efont_cn_16);
static const lgfx::U8g2font FONT_CN_24(lgfx_efont_cn_24);

// 字符串里是否含非 ASCII（中文）字节
static inline bool hasCJK(const char *s)
{
  if(!s) return false;
  for(; *s; ++s) if((uint8_t)*s >= 0x80) return true;
  return false;
}

// 按内容选字体：中文走 CN 字库，ASCII 保持原字体（数字/单位视觉不变）
static inline const lgfx::IFont *fontSmall(const char *s, const lgfx::IFont *latin)
{
  return hasCJK(s) ? (const lgfx::IFont *)&FONT_CN_16 : latin;
}

static inline const lgfx::IFont *fontLarge(const char *s, const lgfx::IFont *latin)
{
  return hasCJK(s) ? (const lgfx::IFont *)&FONT_CN_24 : latin;
}
