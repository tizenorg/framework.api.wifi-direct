Name:       capi-network-wifi-direct
Summary:    Network WiFi-Direct library in Tizen CAPI
Version:    1.2.45
Release:    1
Group:      Connectivity/Wireless
License:    Apache-2.0
Source0:    %{name}-%{version}.tar.gz
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  pkgconfig(gio-2.0)
BuildRequires:  pkgconfig(dlog)
BuildRequires:  pkgconfig(vconf)
BuildRequires:  pkgconfig(capi-base-common)
BuildRequires:  pkgconfig(capi-system-info)
BuildRequires:  cmake
BuildRequires:  gettext-devel

%description
wifi direct library (Shared Library)

%package devel
Summary:    WiFi-Direct library (Shared Library) (Developement)
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}
Requires: capi-base-common-devel
%description devel
WiFi-Direct library (Shared Library) (Developement)

#%description

#%package -n test-wifi-direct
#Summary:    Test Application for Wi-Fi Direct
#Group:      TO_BE_FILLED
#Requires:   %{name} = %{version}-%{release}

#%description -n test-wifi-direct
#Test Application for Wi-Fi Direct

%prep
%setup -q

%ifarch %{arm}
export ARCH=arm
%else
export ARCH=i586
%endif

%build

export CFLAGS="$CFLAGS -DTIZEN_DEBUG_ENABLE"
export CXXFLAGS="$CXXFLAGS -DTIZEN_DEBUG_ENABLE"
export FFLAGS="$FFLAGS -DTIZEN_DEBUG_ENABLE"

cmake -DCMAKE_INSTALL_PREFIX=%{_prefix} \
%if "%{?tizen_profile_name}" == "wearable"
	-DTIZEN_FEATURE_SERVICE_DISCOVERY=0 \
	-DTIZEN_FEATURE_WIFI_DISPLAY=0 \
%else
%if "%{?tizen_profile_name}" == "mobile"
	-DTIZEN_FEATURE_SERVICE_DISCOVERY=1 \
	-DTIZEN_FEATURE_WIFI_DISPLAY=1 \
%else
%if "%{?tizen_profile_name}" == "tv"
	-DTIZEN_FEATURE_SERVICE_DISCOVERY=1 \
	-DTIZEN_FEATURE_WIFI_DISPLAY=1 \
	-DTIZEN_TV=1 \
%endif
%endif
%endif

make %{?jobs:-j%jobs}
%install
rm -rf %{buildroot}
%make_install

mkdir -p %{buildroot}/usr/share/license
cp %{_builddir}/%{buildsubdir}/LICENSE.APLv2 %{buildroot}/usr/share/license/%{name}

%post

%postun


%files
%manifest capi-network-wifi-direct.manifest
%defattr(-,root,root,-)
%{_libdir}/libwifi-direct.so
%{_libdir}/libwifi-direct.so.0
%{_libdir}/libwifi-direct.so.0.0
/usr/share/license/%{name}

%files devel
%defattr(-,root,root,-)
%{_libdir}/pkgconfig/capi-network-wifi-direct.pc
%{_includedir}/wifi-direct/wifi-direct.h
%{_includedir}/wifi-direct/wifi-direct-internal.h

#%files -n test-wifi-direct
#%manifest test-wifi-direct.manifest
#%defattr(4755,app,app,4755)
#%{_bindir}/test-wifi-direct
