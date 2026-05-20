/* ===== 23e80c8c0 workers.fishing.memory_reeling:MemoryReelingTracker._f32 ===== */
/* ghidra_name=FUN_23e80c8c0 entry=23e80c8c0 size=4553 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e80c8c0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  code *pcVar11;
  code *pcVar12;
  longlong *plVar13;
  code *pcVar14;
  code *pcVar15;
  undefined4 uVar16;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar8 = _DAT_23eede8c0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eede8c0 == (longlong *)0x0) {
LAB_23e80c901:
    _DAT_23eede8c0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede970,DAT_23eedd0f8,0x28);
  }
  else {
    lVar9 = *_DAT_23eede8c0;
    if (1 < lVar9) {
      *_DAT_23eede8c0 = lVar9 + -1;
      goto LAB_23e80c901;
    }
    if (_DAT_23eede8c0[2] != 0) {
      *_DAT_23eede8c0 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e80c901;
    }
  }
  plVar4 = _DAT_23eede8c0;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eede8c0 + 9;
  lVar3 = *(longlong *)(lVar9 + 8);
  _DAT_23eede8c0[0xf] = lVar3;
  *(longlong **)(lVar9 + 8) = plVar8;
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
  *plVar4 = *plVar4 + 1;
  uVar5 = _DAT_23eedd3c0;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar5);
  if (plVar8 == (longlong *)0x0) {
    uStack_88 = *(undefined8 *)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    pcVar14 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar11 = (code *)0x0;
    uVar16 = 0x11d;
    uStack_80 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar12 = (code *)0x0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e80d153;
  }
  lVar9 = FUN_23e8dc6f0();
  if (lVar9 == 0) {
    FUN_23e915740(param_1,&uStack_68,_DAT_23eedd3c8);
    *plVar8 = *plVar8 + -1;
    pcVar11 = (code *)0x0;
    uStack_88 = uStack_68;
    plVar10 = plStack_58;
    uStack_80 = uStack_60;
    if (*plVar8 == 0) {
      pcVar14 = (code *)0x0;
      pcVar12 = (code *)0x0;
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      uVar16 = 0x11d;
      plVar8 = DAT_23ed6a4f8;
    }
    else {
      pcVar14 = (code *)0x0;
      pcVar12 = (code *)0x0;
      uVar16 = 0x11d;
      plVar8 = DAT_23ed6a4f8;
    }
    goto joined_r0x00023e80d153;
  }
  plVar10 = (longlong *)FUN_23e8c09e0(plVar2,lVar9);
  if (plVar10 == (longlong *)0x0) {
    uStack_88 = *(undefined8 *)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    pcVar12 = (code *)0x0;
    pcVar11 = (code *)0x0;
    uVar16 = 0x11d;
    pcVar14 = (code *)0x0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e80d153;
  }
  *(undefined4 *)(plVar4 + 5) = 0x11d;
  pcVar11 = (code *)FUN_23e914090(param_1,plVar8,plVar10);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (pcVar11 == (code *)0x0) {
    uStack_88 = *(undefined8 *)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    pcVar14 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar12 = (code *)0x0;
    uVar16 = 0x11d;
    uStack_80 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e80d153;
  }
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd3c0);
  if (plVar8 == (longlong *)0x0) {
    uStack_88 = *(undefined8 *)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    pcVar14 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar12 = (code *)0x0;
    uVar16 = 0x11e;
    uStack_80 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e80d153;
  }
  lVar9 = *(longlong *)(DAT_23eedd0f0 + 0x20);
  if (*(char *)(lVar9 + 10) == '\0') {
    plVar10 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd3d0);
    if (plVar10 == (longlong *)0x0) goto LAB_23e80ce33;
    lVar9 = *plVar10;
LAB_23e80d5d2:
    if (lVar9 == 0) goto LAB_23e80ce33;
  }
  else {
    iVar7 = *(int *)(lVar9 + 0xc);
    if (*(int *)(lVar9 + 0xc) == 0) {
      *(int *)(lVar9 + 0xc) = DAT_23ec155d8;
      iVar7 = DAT_23ec155d8;
      DAT_23ec155d8 = DAT_23ec155d8 + 1;
    }
    if (_DAT_23ec155c4 != iVar7) {
      _DAT_23ec155c4 = iVar7;
      _DAT_23eede8b0 = FUN_23e8cbd60(lVar9,_DAT_23eedd3d0,*(undefined8 *)(_DAT_23eedd3d0 + 0x18));
    }
    if (-1 < _DAT_23eede8b0) {
      lVar3 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
      if (*(longlong *)(lVar3 + 8 + _DAT_23eede8b0 * 0x10) != 0) goto LAB_23e80ca8a;
      _DAT_23eede8b0 = FUN_23e8cbd60(lVar9,_DAT_23eedd3d0,*(undefined8 *)(_DAT_23eedd3d0 + 0x18));
      if (-1 < _DAT_23eede8b0) {
        lVar9 = *(longlong *)(lVar3 + 8 + _DAT_23eede8b0 * 0x10);
        goto LAB_23e80d5d2;
      }
    }
LAB_23e80ce33:
    plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd3d0);
    if ((plVar10 == (longlong *)0x0) || (*plVar10 == 0)) {
      FUN_23e915740(param_1,&uStack_68,_DAT_23eedd3d0);
      *plVar8 = *plVar8 + -1;
      uStack_88 = uStack_68;
      plVar10 = plStack_58;
      uStack_80 = uStack_60;
      if (*plVar8 == 0) {
        pcVar14 = (code *)0x0;
        pcVar12 = (code *)0x0;
        (**(code **)(plVar8[1] + 0x30))(plVar8);
        uVar16 = 0x11e;
        plVar8 = DAT_23ed6a4f8;
      }
      else {
        uVar16 = 0x11e;
        pcVar14 = (code *)0x0;
        pcVar12 = (code *)0x0;
        plVar8 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023e80d153;
    }
  }
LAB_23e80ca8a:
  plVar10 = (longlong *)FUN_23e8c09e0(plVar2);
  if (plVar10 == (longlong *)0x0) {
    uStack_88 = *(undefined8 *)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_80 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar8 = *plVar8 + -1;
    pcVar14 = (code *)0x0;
    if (*plVar8 == 0) {
      pcVar12 = (code *)0x0;
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      uVar16 = 0x11e;
      plVar8 = DAT_23ed6a4f8;
    }
    else {
      pcVar12 = (code *)0x0;
      uVar16 = 0x11e;
      plVar8 = DAT_23ed6a4f8;
    }
    goto joined_r0x00023e80d153;
  }
  *(undefined4 *)(plVar4 + 5) = 0x11e;
  pcVar12 = (code *)FUN_23e914090(param_1,plVar8,plVar10);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (pcVar12 == (code *)0x0) {
    uStack_88 = *(undefined8 *)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    pcVar14 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0x11e;
    uStack_80 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = DAT_23ed6a4f8;
    goto joined_r0x00023e80d153;
  }
  plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedd3c0);
  if (plVar13 != (longlong *)0x0) {
    lVar9 = *(longlong *)(DAT_23eedd0f0 + 0x20);
    if (*(char *)(lVar9 + 10) == '\0') {
      plVar8 = (longlong *)FUN_23a37a020(DAT_23eedd0f0,_DAT_23eedd3d8);
      if (plVar8 == (longlong *)0x0) goto LAB_23e80d330;
      lVar9 = *plVar8;
LAB_23e80d326:
      if (lVar9 == 0) goto LAB_23e80d330;
    }
    else {
      iVar7 = *(int *)(lVar9 + 0xc);
      if (*(int *)(lVar9 + 0xc) == 0) {
        *(int *)(lVar9 + 0xc) = DAT_23ec155d8;
        iVar7 = DAT_23ec155d8;
        DAT_23ec155d8 = DAT_23ec155d8 + 1;
      }
      if (_DAT_23ec155c8 != iVar7) {
        _DAT_23ec155c8 = iVar7;
        _DAT_23eede8b8 = FUN_23e8cbd60(lVar9,_DAT_23eedd3d8,*(undefined8 *)(_DAT_23eedd3d8 + 0x18));
      }
      if (-1 < _DAT_23eede8b8) {
        lVar3 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
        if (*(longlong *)(lVar3 + 8 + _DAT_23eede8b8 * 0x10) != 0) goto LAB_23e80cb79;
        _DAT_23eede8b8 = FUN_23e8cbd60(lVar9,_DAT_23eedd3d8,*(undefined8 *)(_DAT_23eedd3d8 + 0x18));
        if (-1 < _DAT_23eede8b8) {
          lVar9 = *(longlong *)(lVar3 + 8 + _DAT_23eede8b8 * 0x10);
          goto LAB_23e80d326;
        }
      }
LAB_23e80d330:
      plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedd3d8);
      if ((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) {
        FUN_23e915740(param_1,&uStack_68,_DAT_23eedd3d8);
        *plVar13 = *plVar13 + -1;
        uStack_88 = uStack_68;
        plVar10 = plStack_58;
        uStack_80 = uStack_60;
        if (*plVar13 == 0) {
          pcVar14 = (code *)0x0;
          (**(code **)(plVar13[1] + 0x30))(plVar13);
          uVar16 = 0x11f;
          plVar8 = DAT_23ed6a4f8;
        }
        else {
          uVar16 = 0x11f;
          pcVar14 = (code *)0x0;
          plVar8 = DAT_23ed6a4f8;
        }
        goto joined_r0x00023e80d153;
      }
    }
LAB_23e80cb79:
    plVar8 = (longlong *)FUN_23e8c09e0(plVar2);
    if (plVar8 == (longlong *)0x0) {
      uStack_88 = *(undefined8 *)(param_1 + 0x60);
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar16 = 0x11f;
      uStack_80 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar13 = *plVar13 + -1;
      pcVar14 = (code *)0x0;
      plVar8 = DAT_23ed6a4f8;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
        uVar16 = 0x11f;
        plVar8 = DAT_23ed6a4f8;
      }
      goto joined_r0x00023e80d153;
    }
    *(undefined4 *)(plVar4 + 5) = 0x11f;
    pcVar14 = (code *)FUN_23e914090(param_1,plVar13,plVar8);
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    pcVar15 = _Py_NoneStruct_exref;
    if (pcVar14 != (code *)0x0) {
      if (((pcVar11 == _Py_NoneStruct_exref) || (pcVar12 == _Py_NoneStruct_exref)) ||
         (pcVar14 == _Py_NoneStruct_exref)) {
LAB_23e80d1f8:
        *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar8 = *(longlong **)(lVar9 + 0x28);
        plVar4 = (longlong *)plVar8[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
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
LAB_23e80d252:
        *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
        if (*(longlong *)pcVar11 == 0) {
          (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
        }
        *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
        if (*(longlong *)pcVar12 == 0) {
          (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
        }
        lVar9 = *(longlong *)pcVar14;
        *(longlong *)pcVar14 = lVar9 + -1;
        if (lVar9 + -1 == 0) {
          (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
        }
        *plVar1 = *plVar1 + -1;
        if (*plVar1 == 0) {
          (**(code **)(plVar1[1] + 0x30))(plVar1);
        }
        *plVar2 = *plVar2 + -1;
        if (*plVar2 != 0) {
          return pcVar15;
        }
        (**(code **)(plVar2[1] + 0x30))(plVar2);
        return pcVar15;
      }
      *(longlong *)pcVar11 = *(longlong *)pcVar11 + 1;
      plVar8 = (longlong *)FUN_23e8d0dd0(_DAT_23eedd3e0,pcVar11);
      if (plVar8 == (longlong *)0x0) {
        uStack_88 = *(undefined8 *)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_80 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
        if (*(longlong *)pcVar11 == 0) {
          (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
        }
      }
      else {
        iVar7 = FUN_23a35f020(plVar8);
        if (iVar7 == -1) {
LAB_23e80d6c5:
          uStack_88 = *(undefined8 *)(param_1 + 0x60);
          plVar10 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uStack_80 = *(undefined8 *)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
          if (*(longlong *)pcVar11 == 0) {
            (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
          }
LAB_23e80d706:
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
        }
        else {
          if (iVar7 == 0) {
            *plVar8 = *plVar8 + 1;
            plVar13 = plVar8;
          }
          else {
            plVar13 = (longlong *)FUN_23e8d0b80(pcVar11,_DAT_23eedd3e8);
            if (plVar13 == (longlong *)0x0) goto LAB_23e80d6c5;
          }
          *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
          if (*(longlong *)pcVar11 == 0) {
            (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          iVar7 = FUN_23a35f020(plVar13);
          if (iVar7 == -1) {
            uStack_88 = *(undefined8 *)(param_1 + 0x60);
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_80 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
              uVar16 = 0x122;
              plVar8 = DAT_23ed6a4f8;
              goto joined_r0x00023e80d153;
            }
          }
          else {
            if (iVar7 != 1) {
LAB_23e80cc97:
              iVar7 = FUN_23a35f020(plVar13);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              if (iVar7 == -1) {
                uStack_88 = *(undefined8 *)(param_1 + 0x60);
                plVar10 = *(longlong **)(param_1 + 0x70);
                uVar16 = 0x122;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uStack_80 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar8 = DAT_23ed6a4f8;
                goto joined_r0x00023e80d153;
              }
              if (iVar7 != 0) {
                lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar8 = *(longlong **)(lVar9 + 0x28);
                plVar4 = (longlong *)plVar8[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
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
                lVar9 = *(longlong *)(param_1 + 0x10);
                plVar8[0xf] = 0;
                pcVar15 = *(code **)(lVar9 + 0xe28);
                if (pcVar15 == (code *)0x0) {
                  pcVar15 = (code *)FUN_23e916a20(PyTuple_Type_exref,3);
                }
                else {
                  uVar5 = *(undefined8 *)(pcVar15 + 0x18);
                  *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
                  *(undefined8 *)(lVar9 + 0xe28) = uVar5;
                  *(undefined8 *)pcVar15 = 1;
                }
                lVar9 = *(longlong *)
                         (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
                uVar5 = *(undefined8 *)(pcVar15 + -8);
                puVar6 = *(undefined8 **)(lVar9 + 8);
                *puVar6 = pcVar15 + -0x10;
                *(longlong *)(pcVar15 + -0x10) = lVar9;
                *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)uVar5 & 3) | (ulonglong)puVar6;
                *(code **)(lVar9 + 8) = pcVar15 + -0x10;
                *(longlong *)pcVar11 = *(longlong *)pcVar11 + 1;
                *(code **)(pcVar15 + 0x18) = pcVar11;
                *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
                *(code **)(pcVar15 + 0x20) = pcVar12;
                *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
                *(code **)(pcVar15 + 0x28) = pcVar14;
                goto LAB_23e80d252;
              }
              goto LAB_23e80d1f8;
            }
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
            plVar8 = (longlong *)FUN_23e8d0dd0(_DAT_23eedd3e0,pcVar12);
            if (plVar8 == (longlong *)0x0) {
              uStack_88 = *(undefined8 *)(param_1 + 0x60);
              plVar10 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uStack_80 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
              if (*(longlong *)pcVar12 == 0) {
                (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
              }
            }
            else {
              iVar7 = FUN_23a35f020(plVar8);
              if (iVar7 == -1) {
LAB_23e80d948:
                uStack_88 = *(undefined8 *)(param_1 + 0x60);
                plVar10 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uStack_80 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
                if (*(longlong *)pcVar12 == 0) {
                  (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
                }
                goto LAB_23e80d706;
              }
              if (iVar7 == 0) {
                *plVar8 = *plVar8 + 1;
                plVar13 = plVar8;
              }
              else {
                plVar13 = (longlong *)FUN_23e8d0b80(pcVar12,_DAT_23eedd3e8);
                if (plVar13 == (longlong *)0x0) goto LAB_23e80d948;
              }
              *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
              if (*(longlong *)pcVar12 == 0) {
                (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
              }
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              iVar7 = FUN_23a35f020();
              if (iVar7 == -1) {
                uStack_88 = *(undefined8 *)(param_1 + 0x60);
                plVar10 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uStack_80 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  FUN_23a334bc0(plVar13);
                  uVar16 = 0x122;
                  plVar8 = DAT_23ed6a4f8;
                  goto joined_r0x00023e80d153;
                }
              }
              else {
                if (iVar7 != 1) goto LAB_23e80cc97;
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                uVar5 = _DAT_23eedd3f0;
                *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
                plVar8 = (longlong *)FUN_23e8d0dd0(uVar5);
                if (plVar8 == (longlong *)0x0) {
                  uStack_88 = *(undefined8 *)(param_1 + 0x60);
                  plVar10 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uStack_80 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  lVar9 = *(longlong *)pcVar14;
                  *(longlong *)pcVar14 = lVar9 + -1;
                  if (lVar9 + -1 == 0) {
                    FUN_23a334bc0(pcVar14);
                  }
                }
                else {
                  iVar7 = FUN_23a35f020(plVar8);
                  if (iVar7 != -1) {
                    if (iVar7 == 0) {
                      *plVar8 = *plVar8 + 1;
                      plVar13 = plVar8;
                    }
                    else {
                      plVar13 = (longlong *)FUN_23e8d0b80(pcVar14,_DAT_23eedd3f8);
                      if (plVar13 == (longlong *)0x0) goto LAB_23e80da55;
                    }
                    lVar9 = *(longlong *)pcVar14;
                    *(longlong *)pcVar14 = lVar9 + -1;
                    if (lVar9 + -1 == 0) {
                      (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))();
                    }
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    goto LAB_23e80cc97;
                  }
LAB_23e80da55:
                  uStack_88 = *(undefined8 *)(param_1 + 0x60);
                  plVar10 = *(longlong **)(param_1 + 0x70);
                  uStack_80 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  lVar9 = *(longlong *)pcVar14;
                  *(longlong *)pcVar14 = lVar9 + -1;
                  if (lVar9 + -1 == 0) {
                    FUN_23a334bc0(pcVar14);
                  }
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    FUN_23a334bc0(plVar8);
                  }
                }
              }
            }
          }
        }
      }
      uVar16 = 0x122;
      plVar8 = DAT_23ed6a4f8;
      goto joined_r0x00023e80d153;
    }
  }
  uStack_88 = *(undefined8 *)(param_1 + 0x60);
  plVar10 = *(longlong **)(param_1 + 0x70);
  pcVar14 = (code *)0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar16 = 0x11f;
  uStack_80 = *(undefined8 *)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar8 = DAT_23ed6a4f8;
joined_r0x00023e80d153:
  DAT_23ed6a4f8 = plVar8;
  if (plVar10 == (longlong *)0x0) {
    if (plVar8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar8;
      *plVar8 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar15 = _PyRuntime_exref;
    plVar8[2] = 0;
    plVar8[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar9 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar16;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar3 = plVar8[-1];
    puVar6 = *(undefined8 **)(lVar9 + 8);
    *puVar6 = plVar8 + -2;
    plVar8[-2] = lVar9;
    plVar8[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar9 + 8) = plVar8 + -2;
    plVar13 = plVar8;
  }
  else {
    plVar13 = plVar10;
    if ((longlong *)plVar10[3] != plVar4) {
      if (plVar8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar8;
        *plVar8 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar8[3] = (longlong)plVar4;
      *plVar4 = *plVar4 + 1;
      *(undefined4 *)((longlong)plVar8 + 0x24) = uVar16;
      pcVar15 = _PyRuntime_exref;
      *(undefined4 *)(plVar8 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = plVar8[-1];
      puVar6 = *(undefined8 **)(lVar9 + 8);
      *puVar6 = plVar8 + -2;
      plVar8[-2] = lVar9;
      plVar8[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar6;
      lVar3 = *plVar10;
      *(longlong **)(lVar9 + 8) = plVar8 + -2;
      plVar8[2] = (longlong)plVar10;
      plVar13 = plVar8;
      if (lVar3 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar4,"ooooo",plVar1,plVar2,pcVar11,pcVar12,pcVar14);
  if (_DAT_23eede8c0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eede8c0 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar9 + 0x28);
  plVar4 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
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
  if ((pcVar11 != (code *)0x0) &&
     (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
    (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
  }
  if ((pcVar12 != (code *)0x0) &&
     (*(longlong *)pcVar12 = *(longlong *)pcVar12 + -1, *(longlong *)pcVar12 == 0)) {
    (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
  }
  if ((pcVar14 != (code *)0x0) &&
     (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
    (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,uStack_88,uStack_80,plVar13);
  return (code *)0x0;
}
