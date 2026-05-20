/* ===== 23e854310 workers.fishing.window_activator:249 ===== */
/* ghidra_name=FUN_23e854310 entry=23e854310 size=1693 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e854310(longlong param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  code *pcVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar6 = _DAT_23eede340;
  if (_DAT_23eede340 == (longlong *)0x0) {
LAB_23e854347:
    _DAT_23eede340 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede338,DAT_23eede398,8);
  }
  else {
    lVar7 = *_DAT_23eede340;
    if (1 < lVar7) {
      *_DAT_23eede340 = lVar7 + -1;
      goto LAB_23e854347;
    }
    if (_DAT_23eede340[2] != 0) {
      *_DAT_23eede340 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e854347;
    }
  }
  plVar1 = _DAT_23eede340;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eede340 + 9;
  lVar4 = *(longlong *)(lVar7 + 8);
  _DAT_23eede340[0xf] = lVar4;
  *(longlong **)(lVar7 + 8) = plVar6;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar1[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar1[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar1 = *plVar1 + 1;
  *(undefined4 *)(plVar1 + 8) = 0;
  lVar4 = FUN_23e8daad0();
  lVar7 = _DAT_23eedbdd8;
  if (lVar4 == 0) {
    uVar13 = 0xfe;
    FUN_23e915740(param_1,&uStack_68,DAT_23eedbdc8);
    plVar5 = (longlong *)0x0;
    plVar6 = plStack_58;
    uVar11 = uStack_68;
    uVar12 = uStack_60;
  }
  else {
    *(undefined4 *)(plVar1 + 5) = 0xfe;
    plVar5 = (longlong *)FUN_23e915840(param_1,lVar4,_DAT_23eedbdd0,*(undefined8 *)(lVar7 + 0x18));
    if (plVar5 == (longlong *)0x0) {
      uVar11 = *(undefined8 *)(param_1 + 0x60);
      uVar13 = 0xfe;
      plVar6 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar12 = *(undefined8 *)(param_1 + 0x68);
    }
    else {
      iVar3 = FUN_23a35f020(plVar5);
      if (iVar3 == -1) {
        uVar11 = *(undefined8 *)(param_1 + 0x60);
        uVar13 = 0xff;
        plVar6 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar12 = *(undefined8 *)(param_1 + 0x68);
      }
      else if (iVar3 == 0) {
        plVar6 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cf28);
        if ((plVar6 == (longlong *)0x0) || (lVar7 = *plVar6, lVar7 == 0)) {
          PyErr_PrintEx(0);
          Py_Exit(1);
        }
        else {
          *(undefined4 *)(plVar1 + 5) = 0x100;
          plVar6 = (longlong *)FUN_23e94bb80(param_1,lVar7,_DAT_23eedbde0);
          if (plVar6 != (longlong *)0x0) {
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            pcVar8 = _Py_FalseStruct_exref;
            *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23e85448e:
            lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar6 = *(longlong **)(lVar7 + 0x28);
            plVar1 = (longlong *)plVar6[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
            *(undefined4 *)(plVar6 + 8) = 0xffffffff;
            if (plVar1 != (longlong *)0x0) {
              plVar6[2] = 0;
              *plVar1 = *plVar1 + -1;
              if (*plVar1 == 0) {
                (**(code **)(plVar1[1] + 0x30))();
              }
            }
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            plVar6[0xf] = 0;
            *plVar5 = *plVar5 + -1;
            if (*plVar5 != 0) {
              return pcVar8;
            }
            (**(code **)(plVar5[1] + 0x30))(plVar5);
            return pcVar8;
          }
        }
        uVar11 = *(undefined8 *)(param_1 + 0x60);
        uVar13 = 0x100;
        plVar6 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar12 = *(undefined8 *)(param_1 + 0x68);
      }
      else {
        lVar7 = FUN_23e8daad0();
        if (lVar7 == 0) {
          uVar13 = 0x103;
          FUN_23e915740(param_1,&uStack_68,DAT_23eedbdc8);
          plVar6 = plStack_58;
          uVar11 = uStack_68;
          uVar12 = uStack_60;
        }
        else {
          plVar6 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23eedbde8);
          if (plVar6 != (longlong *)0x0) {
            lVar7 = *(longlong *)(param_1 + 0x10);
            plVar9 = *(longlong **)(lVar7 + 0xe18);
            if (plVar9 == (longlong *)0x0) {
              plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
            }
            else {
              lVar4 = plVar9[3];
              *(int *)(lVar7 + 0xeb8) = *(int *)(lVar7 + 0xeb8) + -1;
              *(longlong *)(lVar7 + 0xe18) = lVar4;
              *plVar9 = 1;
            }
            lVar7 = *(longlong *)
                     (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
            lVar4 = plVar9[-1];
            puVar2 = *(undefined8 **)(lVar7 + 8);
            *puVar2 = plVar9 + -2;
            plVar9[-2] = lVar7;
            plVar9[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar2;
            *(longlong **)(lVar7 + 8) = plVar9 + -2;
            uVar11 = _DAT_23eedbdf0;
            *plVar5 = *plVar5 + 1;
            plVar9[3] = (longlong)plVar5;
            plVar10 = (longlong *)FUN_23e8d7870(param_1,uVar11);
            *(undefined4 *)(plVar1 + 5) = 0x103;
            pcVar8 = (code *)FUN_23a334c60(param_1,plVar6,plVar9,plVar10);
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (pcVar8 != (code *)0x0) goto LAB_23e85448e;
          }
          plVar6 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar13 = 0x103;
          uVar11 = *(undefined8 *)(param_1 + 0x60);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar12 = *(undefined8 *)(param_1 + 0x68);
        }
      }
    }
  }
  plVar9 = DAT_23ed6a4f8;
  if (plVar6 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar6 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar10 = plVar9;
    }
    pcVar8 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar1;
    *plVar1 = *plVar1 + 1;
    lVar7 = *(longlong *)(pcVar8 + 0x1f8);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar7 = *(longlong *)(lVar7 + 0x10);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar13;
    lVar7 = *(longlong *)(lVar7 + 0x2e8);
    lVar4 = plVar10[-1];
    puVar2 = *(undefined8 **)(lVar7 + 8);
    *puVar2 = plVar10 + -2;
    plVar10[-2] = lVar7;
    plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar7 + 8) = plVar10 + -2;
  }
  else {
    plVar10 = plVar6;
    if ((longlong *)plVar6[3] != plVar1) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar10 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar10;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar10 = plVar9;
      }
      pcVar8 = _PyRuntime_exref;
      plVar10[3] = (longlong)plVar1;
      *plVar1 = *plVar1 + 1;
      lVar7 = *(longlong *)(pcVar8 + 0x1f8);
      *(undefined4 *)((longlong)plVar10 + 0x24) = uVar13;
      *(undefined4 *)(plVar10 + 4) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar4 = plVar10[-1];
      puVar2 = *(undefined8 **)(lVar7 + 8);
      *puVar2 = plVar10 + -2;
      plVar10[-2] = lVar7;
      plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar2;
      lVar4 = *plVar6;
      *(longlong **)(lVar7 + 8) = plVar10 + -2;
      plVar10[2] = (longlong)plVar6;
      if (lVar4 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
    }
  }
  FUN_23e8bba40(plVar1,&DAT_23ec5e2bc,plVar5);
  if (_DAT_23eede340 == plVar1) {
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    _DAT_23eede340 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar7 + 0x28);
  plVar1 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar1 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      (**(code **)(plVar1[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar6[0xf] = 0;
  if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  FUN_23a33aa70(param_1,uVar11,uVar12,plVar10);
  return (code *)0x0;
}
