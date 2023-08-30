ardillo.lo: ui-ng

ui-ng:
	meson setup -Dtests=false -Dexamples=false --default-library=static $(srcdir)/libui-ng $(builddir)/libui-ng/build
	ninja -C $(builddir)/libui-ng/build
