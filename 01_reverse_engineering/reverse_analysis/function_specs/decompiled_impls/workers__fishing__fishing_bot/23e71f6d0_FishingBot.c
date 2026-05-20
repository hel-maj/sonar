/* ===== 23e71f6d0 workers.fishing.fishing_bot:FishingBot ===== */
/* ghidra_name=FUN_23e71f6d0 entry=23e71f6d0 size=1403 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e71f6d0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  
  plVar9 = _DAT_23eedae98;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedae98 == (longlong *)0x0) {
LAB_23e71f70a:
    _DAT_23eedae98 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaed8,DAT_23eedaeb8,8);
  }
  else {
    lVar2 = *_DAT_23eedae98;
    if (1 < lVar2) {
      *_DAT_23eedae98 = lVar2 + -1;
      goto LAB_23e71f70a;
    }
    if (_DAT_23eedae98[2] != 0) {
      *_DAT_23eedae98 = lVar2 + -1;
      if (lVar2 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e71f70a;
    }
  }
  plVar4 = _DAT_23eedae98;
  lVar2 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eedae98 + 9;
  lVar3 = *(longlong *)(lVar2 + 8);
  _DAT_23eedae98[0xf] = lVar3;
  *(longlong **)(lVar2 + 8) = plVar9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar12 = DAT_23eed8968;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar12);
  if (plVar9 != (longlong *)0x0) {
    *(undefined4 *)(plVar4 + 5) = 0xa8;
    plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed8970);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar10 != (longlong *)0x0) {
      cVar7 = FUN_23e8d9ac0(plVar1,DAT_23eed8978,plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (cVar7 != '\0') {
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8ac8);
        if (plVar9 == (longlong *)0x0) {
          uVar12 = *(undefined8 *)(param_1 + 0x60);
          uVar13 = *(undefined8 *)(param_1 + 0x68);
          uVar14 = 0xa9;
          plVar10 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
        }
        else {
          iVar8 = FUN_23a35f020(plVar9);
          lVar2 = *plVar9 + -1;
          if (iVar8 != -1) {
            *plVar9 = lVar2;
            lVar3 = _DAT_23eed8b48;
            if (lVar2 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
              lVar3 = _DAT_23eed8b48;
            }
            _DAT_23eed8b48 = lVar3;
            if (iVar8 != 0) {
              *(undefined4 *)(plVar4 + 5) = 0xaa;
              plVar9 = (longlong *)
                       FUN_23e915840(param_1,plVar1,DAT_23eed8b40,*(undefined8 *)(lVar3 + 0x18));
              if (plVar9 == (longlong *)0x0) {
                uVar12 = *(undefined8 *)(param_1 + 0x60);
                uVar13 = *(undefined8 *)(param_1 + 0x68);
                uVar14 = 0xaa;
                plVar10 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                goto LAB_23e71f902;
              }
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
            }
            lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar9 = *(longlong **)(lVar2 + 0x28);
            plVar4 = (longlong *)plVar9[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
            *(undefined4 *)(plVar9 + 8) = 0xffffffff;
            if (plVar4 != (longlong *)0x0) {
              plVar9[2] = 0;
              *plVar4 = *plVar4 + -1;
              if (*plVar4 == 0) {
                (**(code **)(plVar4[1] + 0x30))();
              }
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            plVar9[0xf] = 0;
            pcVar6 = _Py_NoneStruct_exref;
            *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
            *plVar1 = *plVar1 + -1;
            if (*plVar1 != 0) {
              return pcVar6;
            }
            (**(code **)(plVar1[1] + 0x30))(plVar1);
            return pcVar6;
          }
          uVar12 = *(undefined8 *)(param_1 + 0x60);
          uVar13 = *(undefined8 *)(param_1 + 0x68);
          plVar10 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar9 = lVar2;
          if (lVar2 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          uVar14 = 0xa9;
        }
        goto LAB_23e71f902;
      }
    }
  }
  plVar10 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar14 = 0xa8;
  uVar12 = *(undefined8 *)(param_1 + 0x60);
  uVar13 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e71f902:
  plVar9 = DAT_23ed6a4f8;
  if (plVar10 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar11 = plVar9;
    }
    pcVar6 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar2 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar2 = *(longlong *)(lVar2 + 0x10);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar14;
    lVar2 = *(longlong *)(lVar2 + 0x2e8);
    lVar3 = plVar11[-1];
    puVar5 = *(undefined8 **)(lVar2 + 8);
    *puVar5 = plVar11 + -2;
    plVar11[-2] = lVar2;
    plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar2 + 8) = plVar11 + -2;
  }
  else {
    plVar11 = plVar10;
    if ((longlong *)plVar10[3] != plVar4) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar11 = plVar9;
      }
      pcVar6 = _PyRuntime_exref;
      plVar11[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      lVar2 = *(longlong *)(pcVar6 + 0x1f8);
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar14;
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar2 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x2e8);
      lVar3 = plVar11[-1];
      puVar5 = *(undefined8 **)(lVar2 + 8);
      *puVar5 = plVar11 + -2;
      plVar11[-2] = lVar2;
      plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
      lVar3 = *plVar10;
      *(longlong **)(lVar2 + 8) = plVar11 + -2;
      plVar11[2] = (longlong)plVar10;
      if (lVar3 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar4,&DAT_23ec5dc90,plVar1);
  if (_DAT_23eedae98 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eedae98 = (longlong *)0x0;
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar2 + 0x28);
  plVar4 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar2 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar12,uVar13,plVar11);
  return (code *)0x0;
}
