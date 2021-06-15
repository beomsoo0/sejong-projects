function varargout = m11_circle(varargin)
% M11_CIRCLE MATLAB code for m11_circle.fig
%      M11_CIRCLE, by itself, creates a new M11_CIRCLE or raises the existing
%      singleton*.
%
%      H = M11_CIRCLE returns the handle to a new M11_CIRCLE or the handle to
%      the existing singleton*.
%
%      M11_CIRCLE('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in M11_CIRCLE.M with the given input arguments.
%
%      M11_CIRCLE('Property','Value',...) creates a new M11_CIRCLE or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before m11_circle_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to m11_circle_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help m11_circle

% Last Modified by GUIDE v2.5 16-May-2015 10:42:04

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @m11_circle_OpeningFcn, ...
                   'gui_OutputFcn',  @m11_circle_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before m11_circle is made visible.
function m11_circle_OpeningFcn(hObject, eventdata, handles, varargin)
handles.output = hObject;
draw_cricle(handles)
guidata(hObject, handles);

% UIWAIT makes m11_circle wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = m11_circle_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on slider movement.
function slider1_Callback(hObject, eventdata, handles)
draw_cricle( handles );

% --- Executes during object creation, after setting all properties.
function slider1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on slider movement.
function slider2_Callback(hObject, eventdata, handles)
% hObject    handle to slider2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider
draw_cricle( handles );

% --- Executes during object creation, after setting all properties.
function slider2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on button press in togglebutton1.
function togglebutton1_Callback(hObject, eventdata, handles)
grids = {'grid on', 'grid off'};
gi    = get(hObject,'Value');
set( hObject, 'String', grids{gi+1} );
draw_cricle( handles );

% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
draw_cricle( handles );

% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

function draw_cricle( handles )

sx = get( handles.slider2, 'Value' );
sy = get( handles.slider1, 'Value' );

ci = get( handles.popupmenu1, 'Value' );
colors = 'bcgwy'; c = colors(ci);

gi = get( handles.togglebutton1, 'Value' );
grids  ={'on', 'off'}; g = grids{gi+1};

t  = linspace(0, 2*pi, 100);
x  = sx * cos(t); y = sy * sin(t);

if gi==0, cla; end;
patch(x, y, c); 
axis([-1 1 -1 1]); axis square; grid(g);

