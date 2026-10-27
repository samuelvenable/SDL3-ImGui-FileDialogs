/*

 MIT License

 Copyright © 2021-2026 Samuel Venable

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

*/

#include <cstring>
#include <iostream>
#if defined(_WIN32)
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include <cstdio>
#include <windows.h>
#elif defined(__APPLE__) && defined(__MACH__)
#include <AppKit/AppKit.h>
#endif

#include <apifilesystem/filesystem.hpp>
#include <apifilesystem/ghc/filesystem.hpp>
#include <apifiledialogs/filedialogs.hpp>

#if defined(_WIN32)
#undef main
#if defined(_MSC_VER)
#pragma comment(linker, "/subsystem:console /entry:mainCRTStartup")
#endif
#endif

using namespace ngs::im;

static std::string remove_trailing_zeros(double numb) {
  std::string strnumb = std::to_string(numb);
  while (!strnumb.empty() && strnumb.find('.') != std::string::npos && (strnumb.back() == '.' || strnumb.back() == '0'))
    strnumb.pop_back();
  return strnumb;
}

int main(int argc, const char **argv) {
  ngs::fs::directory_set_currrent_working(ngs::fs::executable_get_directory());
  #if defined(_WIN32)
  SetConsoleOutputCP(CP_UTF8);
  if (ngs::fs::environment_get_variable("IMGUI_FONT_PATH").empty() && 
  ngs::fs::environment_get_variable("IMGUI_FONT_FILES").empty()) {
    ngs::fs::environment_set_variable("IMGUI_FONT_FILES", 
      std::string("fonts/000-notosans-regular.ttf\n") +
      std::string("fonts/001-notokufiarabic-regular.ttf\n") +
      std::string("fonts/002-notomusic-regular.ttf\n") +
      std::string("fonts/003-notonaskharabic-regular.ttf\n") +
      std::string("fonts/004-notonaskharabicui-regular.ttf\n") +
      std::string("fonts/005-notonastaliqurdu-regular.ttf\n") +
      std::string("fonts/006-notosansadlam-regular.ttf\n") +
      std::string("fonts/007-notosansadlamunjoined-regular.ttf\n") +
      std::string("fonts/008-notosansanatolianhieroglyphs-regular.ttf\n") +
      std::string("fonts/009-notosansarabic-regular.ttf\n") +
      std::string("fonts/010-notosansarabicui-regular.ttf\n") +
      std::string("fonts/011-notosansarmenian-regular.ttf\n") +
      std::string("fonts/012-notosansavestan-regular.ttf\n") +
      std::string("fonts/013-notosansbamum-regular.ttf\n") +
      std::string("fonts/014-notosansbassavah-regular.ttf\n") +
      std::string("fonts/015-notosansbatak-regular.ttf\n") +
      std::string("fonts/016-notosansbengali-regular.ttf\n") +
      std::string("fonts/017-notosansbengaliui-regular.ttf\n") +
      std::string("fonts/018-notosansbhaiksuki-regular.ttf\n") +
      std::string("fonts/019-notosansbrahmi-regular.ttf\n") +
      std::string("fonts/020-notosansbuginese-regular.ttf\n") +
      std::string("fonts/021-notosansbuhid-regular.ttf\n") +
      std::string("fonts/022-notosanscanadianaboriginal-regular.ttf\n") +
      std::string("fonts/023-notosanscarian-regular.ttf\n") +
      std::string("fonts/024-notosanscaucasianalbanian-regular.ttf\n") +
      std::string("fonts/025-notosanschakma-regular.ttf\n") +
      std::string("fonts/026-notosanscham-regular.ttf\n") +
      std::string("fonts/027-notosanscherokee-regular.ttf\n") +
      std::string("fonts/028-notosanscoptic-regular.ttf\n") +
      std::string("fonts/029-notosanscuneiform-regular.ttf\n") +
      std::string("fonts/030-notosanscypriot-regular.ttf\n") +
      std::string("fonts/031-notosansdeseret-regular.ttf\n") +
      std::string("fonts/032-notosansdevanagari-regular.ttf\n") +
      std::string("fonts/033-notosansdevanagariui-regular.ttf\n") +
      std::string("fonts/034-notosansdisplay-regular.ttf\n") +
      std::string("fonts/035-notosansduployan-regular.ttf\n") +
      std::string("fonts/036-notosansegyptianhieroglyphs-regular.ttf\n") +
      std::string("fonts/037-notosanselbasan-regular.ttf\n") +
      std::string("fonts/038-notosansethiopic-regular.ttf\n") +
      std::string("fonts/039-notosansgeorgian-regular.ttf\n") +
      std::string("fonts/040-notosansglagolitic-regular.ttf\n") +
      std::string("fonts/041-notosansgothic-regular.ttf\n") +
      std::string("fonts/042-notosansgrantha-regular.ttf\n") +
      std::string("fonts/043-notosansgujarati-regular.ttf\n") +
      std::string("fonts/044-notosansgujaratiui-regular.ttf\n") +
      std::string("fonts/045-notosansgurmukhi-regular.ttf\n") +
      std::string("fonts/046-notosansgurmukhiui-regular.ttf\n") +
      std::string("fonts/047-notosanshanifirohingya-regular.ttf\n") +
      std::string("fonts/048-notosanshanunoo-regular.ttf\n") +
      std::string("fonts/049-notosanshatran-regular.ttf\n") +
      std::string("fonts/050-notosanshebrew-regular.ttf\n") +
      std::string("fonts/051-notosansimperialaramaic-regular.ttf\n") +
      std::string("fonts/052-notosansindicsiyaqnumbers-regular.ttf\n") +
      std::string("fonts/053-notosansinscriptionalpahlavi-regular.ttf\n") +
      std::string("fonts/054-notosansinscriptionalparthian-regular.ttf\n") +
      std::string("fonts/055-notosansjavanese-regular.ttf\n") +
      std::string("fonts/056-notosanskaithi-regular.ttf\n") +
      std::string("fonts/057-notosanskannada-regular.ttf\n") +
      std::string("fonts/058-notosanskannadaui-regular.ttf\n") +
      std::string("fonts/059-notosanskayahli-regular.ttf\n") +
      std::string("fonts/060-notosanskharoshthi-regular.ttf\n") +
      std::string("fonts/061-notosanskhmer-regular.ttf\n") +
      std::string("fonts/062-notosanskhmerui-regular.ttf\n") +
      std::string("fonts/063-notosanskhojki-regular.ttf\n") +
      std::string("fonts/064-notosanskhudawadi-regular.ttf\n") +
      std::string("fonts/065-notosanslao-regular.ttf\n") +
      std::string("fonts/066-notosanslaoui-regular.ttf\n") +
      std::string("fonts/067-notosanslepcha-regular.ttf\n") +
      std::string("fonts/068-notosanslimbu-regular.ttf\n") +
      std::string("fonts/069-notosanslineara-regular.ttf\n") +
      std::string("fonts/070-notosanslinearb-regular.ttf\n") +
      std::string("fonts/071-notosanslisu-regular.ttf\n") +
      std::string("fonts/072-notosanslycian-regular.ttf\n") +
      std::string("fonts/073-notosanslydian-regular.ttf\n") +
      std::string("fonts/074-notosansmahajani-regular.ttf\n") +
      std::string("fonts/075-notosansmalayalam-regular.ttf\n") +
      std::string("fonts/076-notosansmalayalamui-regular.ttf\n") +
      std::string("fonts/077-notosansmandaic-regular.ttf\n") +
      std::string("fonts/078-notosansmanichaean-regular.ttf\n") +
      std::string("fonts/079-notosansmarchen-regular.ttf\n") +
      std::string("fonts/080-notosansmath-regular.ttf\n") +
      std::string("fonts/081-notosansmayannumerals-regular.ttf\n") +
      std::string("fonts/082-notosansmeeteimayek-regular.ttf\n") +
      std::string("fonts/083-notosansmendekikakui-regular.ttf\n") +
      std::string("fonts/084-notosansmeroitic-regular.ttf\n") +
      std::string("fonts/085-notosansmiao-regular.ttf\n") +
      std::string("fonts/086-notosansmodi-regular.ttf\n") +
      std::string("fonts/087-notosansmongolian-regular.ttf\n") +
      std::string("fonts/088-notosansmono-regular.ttf\n") +
      std::string("fonts/089-notosansmro-regular.ttf\n") +
      std::string("fonts/090-notosansmultani-regular.ttf\n") +
      std::string("fonts/091-notosansmyanmar-regular.ttf\n") +
      std::string("fonts/092-notosansmyanmarui-regular.ttf\n") +
      std::string("fonts/093-notosansnabataean-regular.ttf\n") +
      std::string("fonts/094-notosansnewa-regular.ttf\n") +
      std::string("fonts/095-notosansnewtailue-regular.ttf\n") +
      std::string("fonts/096-notosansnko-regular.ttf\n") +
      std::string("fonts/097-notosansogham-regular.ttf\n") +
      std::string("fonts/098-notosansolchiki-regular.ttf\n") +
      std::string("fonts/099-notosansoldhungarian-regular.ttf\n") +
      std::string("fonts/100-notosansolditalic-regular.ttf\n") +
      std::string("fonts/101-notosansoldnortharabian-regular.ttf\n") +
      std::string("fonts/102-notosansoldpermic-regular.ttf\n") +
      std::string("fonts/103-notosansoldpersian-regular.ttf\n") +
      std::string("fonts/104-notosansoldsogdian-regular.ttf\n") +
      std::string("fonts/105-notosansoldsoutharabian-regular.ttf\n") +
      std::string("fonts/106-notosansoldturkic-regular.ttf\n") +
      std::string("fonts/107-notosansoriya-regular.ttf\n") +
      std::string("fonts/108-notosansoriyaui-regular.ttf\n") +
      std::string("fonts/109-notosansosage-regular.ttf\n") +
      std::string("fonts/110-notosansosmanya-regular.ttf\n") +
      std::string("fonts/111-notosanspahawhhmong-regular.ttf\n") +
      std::string("fonts/112-notosanspalmyrene-regular.ttf\n") +
      std::string("fonts/113-notosanspaucinhau-regular.ttf\n") +
      std::string("fonts/114-notosansphagspa-regular.ttf\n") +
      std::string("fonts/115-notosansphoenician-regular.ttf\n") +
      std::string("fonts/116-notosanspsalterpahlavi-regular.ttf\n") +
      std::string("fonts/117-notosansrejang-regular.ttf\n") +
      std::string("fonts/118-notosansrunic-regular.ttf\n") +
      std::string("fonts/119-notosanssamaritan-regular.ttf\n") +
      std::string("fonts/120-notosanssaurashtra-regular.ttf\n") +
      std::string("fonts/121-notosanssharada-regular.ttf\n") +
      std::string("fonts/122-notosansshavian-regular.ttf\n") +
      std::string("fonts/123-notosanssiddham-regular.ttf\n") +
      std::string("fonts/124-notosanssinhala-regular.ttf\n") +
      std::string("fonts/125-notosanssinhalaui-regular.ttf\n") +
      std::string("fonts/126-notosanssorasompeng-regular.ttf\n") +
      std::string("fonts/127-notosanssundanese-regular.ttf\n") +
      std::string("fonts/128-notosanssylotinagri-regular.ttf\n") +
      std::string("fonts/129-notosanssymbols2-regular.ttf\n") +
      std::string("fonts/130-notosanssymbols-regular.ttf\n") +
      std::string("fonts/131-notosanssyriac-regular.ttf\n") +
      std::string("fonts/132-notosanstagalog-regular.ttf\n") +
      std::string("fonts/133-notosanstagbanwa-regular.ttf\n") +
      std::string("fonts/134-notosanstaile-regular.ttf\n") +
      std::string("fonts/135-notosanstaitham-regular.ttf\n") +
      std::string("fonts/136-notosanstaiviet-regular.ttf\n") +
      std::string("fonts/137-notosanstakri-regular.ttf\n") +
      std::string("fonts/138-notosanstamil-regular.ttf\n") +
      std::string("fonts/139-notosanstamilsupplement-regular.ttf\n") +
      std::string("fonts/140-notosanstamilui-regular.ttf\n") +
      std::string("fonts/141-notosanstelugu-regular.ttf\n") +
      std::string("fonts/142-notosansteluguui-regular.ttf\n") +
      std::string("fonts/143-notosansthaana-regular.ttf\n") +
      std::string("fonts/144-notosansthai-regular.ttf\n") +
      std::string("fonts/145-notosansthaiui-regular.ttf\n") +
      std::string("fonts/146-notosanstibetan-regular.ttf\n") +
      std::string("fonts/147-notosanstifinagh-regular.ttf\n") +
      std::string("fonts/148-notosanstirhuta-regular.ttf\n") +
      std::string("fonts/149-notosansugaritic-regular.ttf\n") +
      std::string("fonts/150-notosansvai-regular.ttf\n") +
      std::string("fonts/151-notosanswarangciti-regular.ttf\n") +
      std::string("fonts/152-notosansyi-regular.ttf\n") +
      std::string("fonts/153-notosanstc-regular.otf\n") +
      std::string("fonts/154-notosansjp-regular.otf\n") +
      std::string("fonts/155-notosanskr-regular.otf\n") +
      std::string("fonts/156-notosanssc-regular.otf\n") +
      std::string("fonts/157-notosanshk-regular.otf"));
  }
  #elif defined(__APPLE__) && defined(__MACH__)
  [[NSApplication sharedApplication] setActivationPolicy:(NSApplicationActivationPolicy)1];
  if (@available(macOS 14.0, *)) {
    [[NSApplication sharedApplication] yieldActivationToApplication:[NSRunningApplication currentApplication]];
    [[NSApplication sharedApplication] activate];
  } else {
    [[NSApplication sharedApplication] activateIgnoringOtherApps:YES];
  }
  #endif
  if (argc <= 2) {
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "--help") == 0)) {
      std::cout << "usage: filedialogs [options]                       " << "\n";
      std::cout << "  options:                                         " << "\n";
      std::cout << "    --help                                         " << "\n";
      std::cout << "    --show-message           msg                   " << "\n";
      std::cout << "    --show-question          msg                   " << "\n";
      std::cout << "    --show-question-ext      msg                   " << "\n";
      std::cout << "    --get-string             msg    def            " << "\n";
      std::cout << "    --get-number             msg    def            " << "\n";
      std::cout << "    --get-open-filename      filter fname          " << "\n";
      std::cout << "    --get-open-filename-ext  filter fname dir title" << "\n";
      std::cout << "    --get-open-filenames     filter fname          " << "\n";
      std::cout << "    --get-open-filenames-ext filter fname dir title" << "\n";
      std::cout << "    --get-save-filename      filter fname          " << "\n";
      std::cout << "    --get-save-filename-ext  filter fname dir title" << "\n";
      std::cout << "    --get-directory          dname                 " << "\n";
      std::cout << "    --get-directory-alt      capt   root           " << "\n";
    }
    return 0;
  } else if (argc == 3 && strcmp(argv[1], "--show-message") == 0) {
    std::cout << show_message(argv[2]) << "\n";
  } else if (argc == 3 && strcmp(argv[1], "--show-question") == 0) {
    std::cout << show_question(argv[2]) << "\n";
  } else if (argc == 3 && strcmp(argv[1], "--show-question-ext") == 0) {
    std::cout << show_question_ext(argv[2]) << "\n";
  } else if (argc == 4 && strcmp(argv[1], "--get-string") == 0) {
    std::cout << get_string(argv[2], argv[3]) << "\n";
  } else if (argc == 4 && strcmp(argv[1], "--get-number") == 0) {
    std::cout << remove_trailing_zeros(get_number(argv[2], strtod(argv[3], nullptr))) << "\n";
  } else if (argc == 4 && strcmp(argv[1], "--get-open-filename") == 0) {
    std::cout << get_open_filename(argv[2], argv[3]) << "\n";
  } else if (argc == 6 && strcmp(argv[1], "--get-open-filename-ext") == 0) {
    std::cout << get_open_filename_ext(argv[2], argv[3], argv[4], argv[5]) << "\n";
  } else if (argc == 4 && strcmp(argv[1], "--get-open-filenames") == 0) {
    std::cout << get_open_filenames(argv[2], argv[3]) << "\n";
  } else if (argc == 6 && strcmp(argv[1], "--get-open-filenames-ext") == 0) {
    std::cout << get_open_filenames_ext(argv[2], argv[3], argv[4], argv[5]) << "\n";
  } else if (argc == 4 && strcmp(argv[1], "--get-save-filename") == 0) {
    std::cout << get_save_filename(argv[2], argv[3]) << "\n";
  } else if (argc == 6 && strcmp(argv[1], "--get-save-filename-ext") == 0) {
    std::cout << get_save_filename_ext(argv[2], argv[3], argv[4], argv[5]) << "\n";
  } else if (argc == 3 && strcmp(argv[1], "--get-directory") == 0) {
    std::cout << get_directory(argv[2]) << "\n";
  } else if (argc == 4 && strcmp(argv[1], "--get-directory-alt") == 0) {
    std::cout << get_directory_alt(argv[2], argv[3]) << "\n";
  }
  return 0;
}
