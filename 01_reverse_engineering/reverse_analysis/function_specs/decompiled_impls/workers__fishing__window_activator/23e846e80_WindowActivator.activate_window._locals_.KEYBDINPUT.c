/* ===== 23e846e80 workers.fishing.window_activator:? ===== */
/* ghidra_name=FUN_23e846e80 entry=23e846e80 size=1945 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e846e80(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  code *pcVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined4 uVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plStack_78;
  longlong *plStack_68;
  longlong *plStack_60;
  longlong *plStack_58;
  
  plVar13 = DAT_23ed6a4e0;
  lVar9 = *param_3;
  if (DAT_23ed6a4e0 == (longlong *)0x0) {
    plVar13 = (longlong *)FUN_23a33a530(&DAT_23ec0fb60);
  }
  else {
    plVar7 = (longlong *)*DAT_23ed6a4e0;
    *DAT_23ed6a4e0 = 1;
    DAT_23ed6a4e0 = plVar7;
    DAT_23ed6a4d8 = DAT_23ed6a4d8 + -1;
  }
  pcVar5 = _PyRuntime_exref;
  plVar7 = _DAT_23eede3a0;
  plVar13[2] = lVar9;
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = plVar13[-1];
  puVar3 = *(undefined8 **)(lVar1 + 8);
  *puVar3 = plVar13 + -2;
  plVar13[-2] = lVar1;
  plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar1 + 8) = plVar13 + -2;
  if (plVar7 == (longlong *)0x0) {
LAB_23e846f2f:
    plVar7 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede390,DAT_23eede398,0x18);
    lVar9 = plVar13[2];
    _DAT_23eede3a0 = plVar7;
  }
  else {
    lVar1 = *plVar7;
    if (1 < lVar1) {
      *plVar7 = lVar1 + -1;
      goto LAB_23e846f2f;
    }
    if (plVar7[2] != 0) {
      *plVar7 = lVar1 + -1;
      if (lVar1 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e846f2f;
    }
  }
  lVar1 = *(longlong *)(param_1 + 0x38);
  lVar2 = *(longlong *)(lVar1 + 8);
  plVar7[0xf] = lVar2;
  *(longlong **)(lVar1 + 8) = plVar7 + 9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar7[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar7[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar7 = *plVar7 + 1;
  *(undefined4 *)(plVar7 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(lVar9,DAT_23ed6ce98);
  if (plVar8 == (longlong *)0x0) {
    plStack_78 = *(longlong **)(param_1 + 0x60);
    plVar16 = *(longlong **)(param_1 + 0x70);
    plVar8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar11 = *(longlong **)(param_1 + 0x68);
    uVar15 = 0x2e;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
  }
  else {
    *(undefined4 *)(plVar7 + 5) = 0x2e;
    lVar9 = FUN_23e91a870(param_1,plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (lVar9 == 0) {
      plStack_78 = *(longlong **)(param_1 + 0x60);
      plVar11 = *(longlong **)(param_1 + 0x68);
      plVar10 = (longlong *)0x0;
      plVar16 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar15 = 0x2e;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar8 = (longlong *)0x0;
    }
    else {
      plVar8 = (longlong *)plVar13[2];
      plVar13[2] = lVar9;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      uVar4 = DAT_23eede398;
      *plVar13 = *plVar13 + 1;
      plStack_68 = plVar13;
      plVar10 = (longlong *)
                FUN_23e93e1e0(FUN_23e847660,_DAT_23eedbb80,_DAT_23eedbb88,_DAT_23eede388,0,0,uVar4,0
                              ,&plStack_68,1);
      lVar9 = *(longlong *)(param_1 + 0x10);
      if (*(int *)(lVar9 + 0x1188) == 0) {
        plVar8 = (longlong *)FUN_23a33a530(PyList_Type_exref);
      }
      else {
        iVar6 = *(int *)(lVar9 + 0x1188) + -1;
        *(int *)(lVar9 + 0x1188) = iVar6;
        plVar8 = *(longlong **)(lVar9 + 0xf08 + (longlong)iVar6 * 8);
        *plVar8 = 1;
      }
      plVar8[2] = 0;
      plVar8[4] = 0;
      lVar9 = *(longlong *)(pcVar5 + 0x1f8);
      plVar8[3] = 0;
      lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
      lVar1 = plVar8[-1];
      puVar3 = *(undefined8 **)(lVar9 + 8);
      *puVar3 = plVar8 + -2;
      plVar8[-2] = lVar9;
      plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
      *(longlong **)(lVar9 + 8) = plVar8 + -2;
      lVar9 = FUN_23e8daec0();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,&plStack_68,DAT_23eedbb90);
        uVar15 = 0x3f;
        plStack_78 = plStack_68;
        plVar16 = plStack_58;
        plVar11 = plStack_60;
      }
      else {
        *(undefined4 *)(plVar7 + 5) = 0x3f;
        plStack_68 = plVar10;
        plStack_60 = plVar8;
        plVar11 = (longlong *)FUN_23e954670(param_1,lVar9,_DAT_23eedbb98,&plStack_68);
        if (plVar11 == (longlong *)0x0) {
          plStack_78 = *(longlong **)(param_1 + 0x60);
          uVar15 = 0x3f;
          plVar16 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar11 = *(longlong **)(param_1 + 0x68);
        }
        else {
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
            iVar6 = FUN_23a35f020(plVar8);
            pcVar12 = _Py_NoneStruct_exref;
          }
          else {
            iVar6 = FUN_23a35f020(plVar8);
            pcVar12 = _Py_NoneStruct_exref;
          }
          _Py_NoneStruct_exref = pcVar12;
          if (iVar6 != 1) {
            *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
LAB_23e847168:
            lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar7 = *(longlong **)(lVar9 + 0x28);
            plVar11 = (longlong *)plVar7[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
            *(undefined4 *)(plVar7 + 8) = 0xffffffff;
            if (plVar11 != (longlong *)0x0) {
              plVar7[2] = 0;
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))();
              }
            }
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            plVar7[0xf] = 0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
              return pcVar12;
            }
            return pcVar12;
          }
          plVar11 = (longlong *)FUN_23a388650(param_1,plVar8,DAT_23ed6ccf0,0);
          if (plVar11 != (longlong *)0x0) {
            pcVar12 = (code *)FUN_23a388650(param_1,plVar11,DAT_23ed6ccf0,0);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (pcVar12 != (code *)0x0) goto LAB_23e847168;
          }
          plStack_78 = *(longlong **)(param_1 + 0x60);
          uVar15 = 0x42;
          plVar16 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar11 = *(longlong **)(param_1 + 0x68);
        }
      }
    }
  }
  plVar14 = DAT_23ed6a4f8;
  if (plVar16 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    lVar9 = *(longlong *)(pcVar5 + 0x1f8);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar15;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar1 = plVar14[-1];
    puVar3 = *(undefined8 **)(lVar9 + 8);
    *puVar3 = plVar14 + -2;
    plVar14[-2] = lVar9;
    plVar14[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar9 + 8) = plVar14 + -2;
    plVar17 = plVar14;
  }
  else {
    plVar17 = plVar16;
    if ((longlong *)plVar16[3] != plVar7) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar17 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar17;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar14[3] = (longlong)plVar7;
      *plVar7 = *plVar7 + 1;
      *(undefined4 *)((longlong)plVar14 + 0x24) = uVar15;
      lVar9 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined4 *)(plVar14 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
      lVar1 = plVar14[-1];
      puVar3 = *(undefined8 **)(lVar9 + 8);
      *puVar3 = plVar14 + -2;
      plVar14[-2] = lVar9;
      plVar14[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar3;
      lVar1 = *plVar16;
      *(longlong **)(lVar9 + 8) = plVar14 + -2;
      plVar14[2] = (longlong)plVar16;
      plVar17 = plVar14;
      if (lVar1 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
    }
  }
  FUN_23e8bba40(plVar7,&DAT_23ec5e40a,plVar13,plVar10,plVar8);
  if (_DAT_23eede3a0 == plVar7) {
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    _DAT_23eede3a0 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar9 + 0x28);
  plVar16 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar16 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  FUN_23a33aa70(param_1,plStack_78,plVar11,plVar17);
  return (code *)0x0;
}
