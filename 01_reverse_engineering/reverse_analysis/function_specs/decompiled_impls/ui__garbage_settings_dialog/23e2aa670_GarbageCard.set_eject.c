/* ===== 23e2aa670 ui.garbage_settings_dialog:? ===== */
/* ghidra_name=FUN_23e2aa670 entry=23e2aa670 size=2466 */

code * FUN_23e2aa670(longlong param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  char cVar7;
  longlong *plVar8;
  longlong *plVar9;
  int iVar10;
  longlong lVar11;
  code *pcVar12;
  undefined4 uVar13;
  code *local_68;
  undefined8 uStack_60;
  longlong *local_58 [3];
  
  plVar8 = DAT_23eeb0400;
  pcVar1 = (code *)*param_3;
  plVar2 = (longlong *)param_3[1];
  local_58[0] = (longlong *)0x0;
  local_68 = (code *)0x0;
  uStack_60 = 0;
  if (DAT_23eeb0400 == (longlong *)0x0) {
LAB_23e2aa6c3:
    DAT_23eeb0400 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0488,DAT_23eeb0428,0x18);
  }
  else {
    lVar11 = *DAT_23eeb0400;
    if (1 < lVar11) {
      *DAT_23eeb0400 = lVar11 + -1;
      goto LAB_23e2aa6c3;
    }
    if (DAT_23eeb0400[2] != 0) {
      *DAT_23eeb0400 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e2aa6c3;
    }
  }
  plVar4 = DAT_23eeb0400;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23eeb0400 + 9;
  lVar3 = *(longlong *)(lVar11 + 8);
  DAT_23eeb0400[0xf] = lVar3;
  *(longlong **)(lVar11 + 8) = plVar8;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  lVar11 = *(longlong *)(param_2 + 0xd8);
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  pcVar6 = _Py_NoneStruct_exref;
  lVar11 = *(longlong *)(lVar11 + 0x10);
  if (lVar11 == 0) {
    if (((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x40) == 0) ||
       ((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x20) == 0)) {
      lVar11 = *(longlong *)(DAT_23ed6cd40 + 0x38);
    }
    else {
      lVar11 = DAT_23ed6cd40 + 0x30;
    }
    uStack_60 = PyUnicode_FromFormat
                          ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                           ,lVar11);
    local_68 = *(code **)PyExc_NameError_exref;
    *(longlong *)local_68 = *(longlong *)local_68 + 1;
    local_58[0] = (longlong *)0x0;
    if (local_68 != _Py_NoneStruct_exref) {
      FUN_23e91b1b0(param_1,&local_68,&uStack_60,local_58);
    }
    uVar13 = 0x5b;
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),uStack_60);
    plVar9 = DAT_23ed6a4f8;
    plVar8 = local_58[0];
    goto joined_r0x00023e2aaafc;
  }
  pcVar12 = (code *)0x0;
  if (pcVar1 != _Py_NoneStruct_exref) {
    pcVar12 = pcVar1;
  }
  plVar8 = (longlong *)FUN_23e9543b0(param_1,DAT_23eeae260,lVar11,pcVar12);
  if (plVar8 != (longlong *)0x0) {
    *(undefined4 *)(plVar4 + 5) = 0x5b;
    plVar9 = (longlong *)FUN_23e915840(param_1,plVar8,DAT_23ed6cdb0,plVar2);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      lVar11 = DAT_23eeae428;
      *(undefined4 *)(plVar4 + 5) = 0x5c;
      plVar8 = (longlong *)
               FUN_23e915840(param_1,pcVar1,DAT_23eeae420,*(undefined8 *)(lVar11 + 0x18));
      if (plVar8 == (longlong *)0x0) {
        local_68 = *(code **)(param_1 + 0x60);
        uStack_60 = *(undefined8 *)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x70);
        uVar13 = 0x5c;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar9 = DAT_23ed6a4f8;
        goto joined_r0x00023e2aaafc;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      lVar11 = DAT_23eeae438;
      *(undefined4 *)(plVar4 + 5) = 0x5d;
      plVar8 = (longlong *)FUN_23e954670(param_1,pcVar1,DAT_23eeae430,lVar11 + 0x18);
      if (plVar8 == (longlong *)0x0) {
        local_68 = *(code **)(param_1 + 0x60);
        uStack_60 = *(undefined8 *)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x70);
        uVar13 = 0x5d;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar9 = DAT_23ed6a4f8;
        goto joined_r0x00023e2aaafc;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      lVar3 = DAT_23ed6cce8;
      lVar11 = *(longlong *)(param_1 + 0x10);
      plVar8 = *(longlong **)(DAT_23ed6cce8 + 0x20);
      iVar10 = *(int *)(lVar11 + 0x1410);
      *plVar8 = *plVar8 + 1;
      if (iVar10 == 0) {
        plVar9 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
        plVar8 = *(longlong **)(lVar3 + 0x20);
      }
      else {
        iVar10 = iVar10 + -1;
        *(int *)(lVar11 + 0x1410) = iVar10;
        plVar9 = *(longlong **)(lVar11 + 0x1190 + (longlong)iVar10 * 8);
        *plVar9 = 1;
      }
      lVar11 = *(longlong *)(lVar3 + 0x28);
      plVar9[2] = 0;
      plVar9[3] = 1;
      plVar9[4] = (longlong)plVar8;
      plVar9[5] = lVar11;
      cVar7 = FUN_23e8d9ac0(pcVar1,DAT_23eeae440,plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (cVar7 == '\0') {
        local_68 = *(code **)(param_1 + 0x60);
        uStack_60 = *(undefined8 *)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x70);
        uVar13 = 0x5e;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar9 = DAT_23ed6a4f8;
        goto joined_r0x00023e2aaafc;
      }
      lVar11 = *(longlong *)(DAT_23eeae260 + 0x20);
      if (*(char *)(lVar11 + 10) == '\0') {
        plVar8 = (longlong *)FUN_23a37a020(DAT_23eeae260,DAT_23eeae448);
        if (plVar8 == (longlong *)0x0) goto LAB_23e2aace9;
        lVar11 = *plVar8;
LAB_23e2aafb0:
        if (lVar11 == 0) goto LAB_23e2aace9;
      }
      else {
        iVar10 = *(int *)(lVar11 + 0xc);
        if (*(int *)(lVar11 + 0xc) == 0) {
          *(int *)(lVar11 + 0xc) = DAT_23ec14e8c;
          iVar10 = DAT_23ec14e8c;
          DAT_23ec14e8c = DAT_23ec14e8c + 1;
        }
        if (DAT_23ec14e84 != iVar10) {
          DAT_23ec14e84 = iVar10;
          DAT_23eeb03f8 = FUN_23e8cbd60(lVar11,DAT_23eeae448,*(undefined8 *)(DAT_23eeae448 + 0x18));
        }
        if (-1 < DAT_23eeb03f8) {
          lVar3 = lVar11 + 0x20 + (1L << (*(byte *)(lVar11 + 9) & 0x3f));
          if (*(longlong *)(lVar3 + 8 + DAT_23eeb03f8 * 0x10) != 0) goto LAB_23e2aa932;
          DAT_23eeb03f8 = FUN_23e8cbd60(lVar11,DAT_23eeae448,*(undefined8 *)(DAT_23eeae448 + 0x18));
          if (-1 < DAT_23eeb03f8) {
            lVar11 = *(longlong *)(lVar3 + 8 + DAT_23eeb03f8 * 0x10);
            goto LAB_23e2aafb0;
          }
        }
LAB_23e2aace9:
        plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeae448);
        if ((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) {
          uVar13 = 0x5f;
          FUN_23e915740(param_1,&local_68,DAT_23eeae448);
          plVar9 = DAT_23ed6a4f8;
          plVar8 = local_58[0];
          goto joined_r0x00023e2aaafc;
        }
      }
LAB_23e2aa932:
      *(undefined4 *)(plVar4 + 5) = 0x5f;
      plVar8 = (longlong *)FUN_23e91a870(param_1);
      if (plVar8 != (longlong *)0x0) {
        cVar7 = FUN_23e8d9ac0(pcVar1,DAT_23eeae450,plVar8);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (cVar7 != '\0') {
          *(undefined4 *)(plVar4 + 5) = 0x60;
          plVar8 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23eeae458);
          if (plVar8 == (longlong *)0x0) {
            local_68 = *(code **)(param_1 + 0x60);
            uStack_60 = *(undefined8 *)(param_1 + 0x68);
            plVar8 = *(longlong **)(param_1 + 0x70);
            uVar13 = 0x60;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar9 = DAT_23ed6a4f8;
          }
          else {
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            *(undefined4 *)(plVar4 + 5) = 0x61;
            plVar8 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23eeae460);
            if (plVar8 != (longlong *)0x0) {
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar8 = *(longlong **)(lVar11 + 0x28);
              plVar4 = (longlong *)plVar8[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
              *(undefined4 *)(plVar8 + 8) = 0xffffffff;
              if (plVar4 != (longlong *)0x0) {
                plVar8[2] = 0;
                *plVar4 = *plVar4 + -1;
                if (*plVar4 == 0) {
                  (**(code **)(plVar4[1] + 0x30))();
                }
              }
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              *(longlong *)pcVar6 = *(longlong *)pcVar6 + 1;
              plVar8[0xf] = 0;
              *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
              if (*(longlong *)pcVar1 == 0) {
                (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
              }
              *plVar2 = *plVar2 + -1;
              if (*plVar2 != 0) {
                return pcVar6;
              }
              (**(code **)(plVar2[1] + 0x30))(plVar2);
              return pcVar6;
            }
            local_68 = *(code **)(param_1 + 0x60);
            uStack_60 = *(undefined8 *)(param_1 + 0x68);
            plVar8 = *(longlong **)(param_1 + 0x70);
            uVar13 = 0x61;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar9 = DAT_23ed6a4f8;
          }
          goto joined_r0x00023e2aaafc;
        }
      }
      local_68 = *(code **)(param_1 + 0x60);
      uStack_60 = *(undefined8 *)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x70);
      uVar13 = 0x5f;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = DAT_23ed6a4f8;
      goto joined_r0x00023e2aaafc;
    }
  }
  plVar8 = *(longlong **)(param_1 + 0x70);
  local_68 = *(code **)(param_1 + 0x60);
  uStack_60 = *(undefined8 *)(param_1 + 0x68);
  uVar13 = 0x5b;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar9 = DAT_23ed6a4f8;
joined_r0x00023e2aaafc:
  DAT_23ed6a4f8 = plVar9;
  local_58[0] = plVar8;
  if (plVar8 == (longlong *)0x0) {
    if (plVar9 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar9;
      *plVar9 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar11 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar13;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar3 = plVar9[-1];
    puVar5 = *(undefined8 **)(lVar11 + 8);
    *puVar5 = plVar9 + -2;
    plVar9[-2] = lVar11;
    plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar11 + 8) = plVar9 + -2;
    plVar8 = plVar9;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))(local_58[0]);
    }
  }
  else if ((longlong *)plVar8[3] != plVar4) {
    if (plVar9 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar9;
      *plVar9 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar9[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar11 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar13;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar3 = plVar9[-1];
    puVar5 = *(undefined8 **)(lVar11 + 8);
    *puVar5 = plVar9 + -2;
    plVar9[-2] = lVar11;
    plVar9[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar11 + 8) = plVar9 + -2;
    plVar9[2] = (longlong)plVar8;
    *plVar8 = *plVar8 + 1;
    plVar8 = plVar9;
    if ((local_58[0] != (longlong *)0x0) && (*local_58[0] = *local_58[0] + -1, *local_58[0] == 0)) {
      (**(code **)(local_58[0][1] + 0x30))();
    }
  }
  local_58[0] = plVar8;
  FUN_23e8bba40(plVar4,&DAT_23ec5b343,pcVar1,plVar2,*(undefined8 *)(param_2 + 0xd8));
  if (DAT_23eeb0400 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23eeb0400 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar11 + 0x28);
  plVar4 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
  if (*(longlong *)pcVar1 == 0) {
    (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_68,uStack_60,local_58[0]);
  return (code *)0x0;
}
