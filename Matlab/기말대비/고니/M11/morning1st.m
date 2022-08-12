function varargout = morning1st(varargin)
% MORNING1ST MATLAB code for morning1st.fig
%      MORNING1ST, by itself, creates a new MORNING1ST or raises the existing
%      singleton*.
%
%      H = MORNING1ST returns the handle to a new MORNING1ST or the handle to
%      the existing singleton*.
%
%      MORNING1ST('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in MORNING1ST.M with the given input arguments.
%
%      MORNING1ST('Property','Value',...) creates a new MORNING1ST or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before morning1st_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to morning1st_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help morning1st

% Last Modified by GUIDE v2.5 05-Nov-2013 10:42:31

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @morning1st_OpeningFcn, ...
                   'gui_OutputFcn',  @morning1st_OutputFcn, ...
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


% --- Executes just before morning1st is made visible.
function morning1st_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to morning1st (see VARARGIN)

% Choose default command line output for morning1st
handles.output = hObject;

plot( rand(10) );
set( gca, 'Color', [rand rand rand] );


% Update handles structure
guidata(hObject, handles);

% UIWAIT makes morning1st wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = morning1st_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
plot( rand(10) );
set( gca, 'Color', [rand rand rand] );


% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

disp('Bye!');
% Hint: delete(hObject) closes the figure
delete(hObject);


% --- Executes when selected object is changed in uipanel1.
function uipanel1_SelectionChangeFcn(hObject, eventdata, handles)
% hObject    handle to the selected object in uipanel1 
% eventdata  structure with the following fields (see UIBUTTONGROUP)
%	EventName: string 'SelectionChanged' (read only)
%	OldValue: handle of the previously selected object or empty if none was selected
%	NewValue: handle of the currently selected object
% handles    structure with handles and user data (see GUIDATA)

switch eventdata.NewValue
    case handles.radiobutton3
        set( gca, 'Color', 'b' );
    case handles.radiobutton2
        set( gca, 'Color', 'g' );
    case handles.radiobutton1
        set( gca, 'Color', 'r' );
end
        



